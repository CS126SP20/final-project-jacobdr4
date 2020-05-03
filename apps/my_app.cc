// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>

namespace myapp {

using cinder::app::Event;
using cinder::app::KeyEvent;
using cinder::app::MouseEvent;
using namespace std;

Tool MyApp::tool;

MyApp::MyApp() {
  background_color = Color(0, 0, 0);
}

void MyApp::setup() {
  mUi = SuperCanvas::create("Pixel Paint");
  CreateButtons();
  tool = Tool::line;
  tool_radio->activate("Line");
  CreateColorSlider();
  mUi->autoSizeToFitSubviews();
  mUi->load(getSaveLoadPath());
}

void MyApp::update() {
  ColorSliderSettings();

  if (tool == Tool::save) {
    SaveData();
    tool = Tool::line;
    tool_radio->activate("Line");
  }
}

void MyApp::draw() {
  if (tool == Tool::clear) {
    Clear();
  }

  if (tool == Tool::fill) {
    SetBackgroundColor();
  }

  cinder::gl::clear(background_color);
  for (Shape s : shapes) {
    s.Display();
  }
}

void MyApp::keyDown(KeyEvent event) {}

void MyApp::cleanup() { mUi->save(getSaveLoadPath()); }

fs::path MyApp::getSaveLoadPath() {
  fs::path path = getAssetPath("");
  path += "/" + mUi->getName() + ".json";
  return path;
}

void MyApp::SetBackgroundColor() { background_color = Color(red, green, blue); }

void MyApp::CreateButtons() {
  vector<std::string> tools = {"Line", "Scribble", "Rect", "Fill", "Clear", "Save", "Load"};
  tool_radio = Radio::create("Tools", tools);
  tool_radio->setCallback(OnButtonPress);
  mUi->addSubViewDown(tool_radio, Alignment::LEFT);
}

void MyApp::CreateColorSlider() {
  red = 0.0;
  blue = 0.0;
  green = 0.0;
  vector<MultiSlider::Data> slider_data;
  slider_data.push_back(MultiSlider::Data("RED", &red, 0.0, 1.0));
  slider_data.push_back(MultiSlider::Data("GREEN", &green, 0.0, 1.0));
  slider_data.push_back(MultiSlider::Data("BLUE", &blue, 0.0, 1.0));

  color_slider = MultiSlider::create("Paint Color", slider_data,
                                     MultiSlider::Format().crossFader());
  color_slider->setDrawBoundsOutline(false);
  mUi->addSubViewDown(color_slider, Alignment::LEFT);
}

void MyApp::ColorSliderSettings() {
  color_slider->setColorOutline(ColorA(red, green, blue));
  color_slider->setColorOutlineHighlight(ColorA(red, green, blue));
  color_slider->setColorFillHighlight(ColorA(red, green, blue));
}

void MyApp::Clear() {
  mShape.clear();
  shapes.clear();
  cinder::gl::clear();
}

void MyApp::OnButtonPress(string name, bool value) {
  if (name == "Line" && value) {
    tool = Tool::line;
  } else if (name == "Rect" && value) {
    tool = Tool::rect;
  } else if (name == "Fill" && value) {
    tool = Tool::fill;
  } else if (name == "Scribble" && value) {
    tool = Tool::scribble;
  } else if (name == "Clear" && value) {
    tool = Tool::clear;
  } else if (name == "Save" && value) {
    tool = Tool::save;
  } else if (name == "Load" && value) {
    tool = Tool::load;
  }
}

void MyApp::SaveData() {
 database db("shapesave.db");

  try {
    db <<
       "create table if not exists shapes ("
       "   _id integer primary key autoincrement not null,"
       "   shapetype text,"
       "   startx int,"
       "   starty int,"
       "   endx int,"
       "   endy int,"
       "   red real,"
       "   green real,"
       "   blue real"
       ");";
  } catch (std::exception e) {
    std::cout << "Error creating leaderboard";
  }

  db << "DELETE FROM shapes";

  for (Shape shape : shapes) {
    db << u"insert into shapes (shapetype,startx,starty,endx,endy,red,green,blue) values (?,?,?,?,?,?,?,?);" // utf16 query string
       << shape.GetShapeType()
       << shape.GetStartX()
       << shape.GetStartY()
       << shape.GetEndX()
       << shape.GetEndY()
       << shape.GetColor().r
       << shape.GetColor().g
       << shape.GetColor().b;
  }
}

void MyApp::mouseDown(MouseEvent event) {
  start_mouseX = event.getX();
  start_mouseY = event.getY();

  if (tool == Tool::line) {
    shapes.push_back(Shape(Color(red, green, blue), ShapeType::line,
                           start_mouseX, start_mouseY));
  }

  if (tool == Tool::rect) {
    shapes.push_back(Shape(Color(red, green, blue), ShapeType::rect,
                           start_mouseX, start_mouseY));
  }

  if (tool == Tool::scribble) {
    shapes.push_back(Shape(Color(red, green, blue), ShapeType::scribble,
                           start_mouseX, start_mouseY));
  }
}

void MyApp::mouseUp(MouseEvent event) {

}

void MyApp::mouseDrag(MouseEvent event) {
  current_mouseX = event.getX();
  current_mouseY = event.getY();

  if (tool != Tool::fill && tool != Tool::clear) {
    shapes[shapes.size() - 1].Update(current_mouseX, current_mouseY);
  }
}

void MyApp::mouseMove(MouseEvent event) {}
}  // namespace myapp
