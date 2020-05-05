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
  saved_background_color = Color(0, 0, 0);
  can_draw = false;
}

void MyApp::setup() {
  mUi = SuperCanvas::create("Pixel Paint");
  CreateButtons();
  tool = Tool::line;
  radio->activate("Line");
  CreateColorSlider();
  mUi->autoSizeToFitSubviews();
  mUi->load(getSaveLoadPath());
}

void MyApp::update() {
  ColorSliderSettings();

  if (tool == Tool::save) {
    SaveData();
    tool = Tool::line;
    radio->activate("Line");
  }

  if (tool == Tool::load) {
    LoadData();
    tool = Tool::line;
    radio->activate("Line");
  }

  if (tool == Tool::undo) {
    Undo();
    tool = Tool::line;
    radio->activate("Line");
  }
}

void MyApp::draw() {
  if (tool == Tool::clear) {
    shapes.clear();
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
  vector<std::string> tools = {"Line",  "Scribble", "Rect", "Ellipse", "Fill",
                               "Clear", "Save",     "Load", "Undo"};
  radio = Radio::create("Tools", tools);
  radio->setCallback(OnButtonPress);
  mUi->addSubViewDown(radio, Alignment::LEFT);
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

void MyApp::OnButtonPress(string name, bool value) {
  if (name == "Line" && value) {
    tool = Tool::line;
  } else if (name == "Rect" && value) {
    tool = Tool::rect;
  } else if (name == "Fill" && value) {
    tool = Tool::fill;
  } else if (name == "Scribble" && value) {
    tool = Tool::scribble;
  } else if (name == "Ellipse" && value) {
    tool = Tool::ellipse;
  } else if (name == "Clear" && value) {
    tool = Tool::clear;
  } else if (name == "Save" && value) {
    tool = Tool::save;
  } else if (name == "Load" && value) {
    tool = Tool::load;
  } else if (name == "Undo" && value) {
    tool = Tool::undo;
  }
}

void MyApp::SaveData() {
  saved_shapes.clear();

  for (Shape s : shapes) {
    saved_shapes.push_back(s);
  }
  saved_background_color = background_color;
}

void MyApp::LoadData() {
  shapes.clear();
  background_color = saved_background_color;
  shapes = saved_shapes;
}

void MyApp::Undo() {
  if (shapes.size() >= 1) {
    shapes.pop_back();
  }
}

ShapeType MyApp::GetShapeTypeFromTool() {
  if (tool == Tool::line) {
    return ShapeType::line;
  } else if (tool == Tool::scribble) {
    return ShapeType::scribble;
  } else if (tool == Tool::rect) {
    return ShapeType::rect;
  } else if (tool == Tool::ellipse) {
    return ShapeType::ellipse;
  } else {
    return ShapeType::none;
  }
}

bool MyApp::MouseInBounds(const int &mousex, const int &mousey) {
  return mousex > mUi->getHeight() || mousey > mUi->getHeight();
}

void MyApp::mouseDown(MouseEvent event) {
  start_mouseX = event.getX();
  start_mouseY = event.getY();
  ShapeType shapetype = GetShapeTypeFromTool();
  can_draw = false;

  if (MouseInBounds(start_mouseX, start_mouseY) && shapetype != ShapeType::none) {
    can_draw = true;
    shapes.push_back(Shape(Color(red, green, blue), shapetype,
                           start_mouseX, start_mouseY));
  }
}

void MyApp::mouseUp(MouseEvent event) {}

void MyApp::mouseDrag(MouseEvent event) {
  current_mouseX = event.getX();
  current_mouseY = event.getY();

  if (can_draw && tool != Tool::fill && tool != Tool::clear) {
    shapes[shapes.size() - 1].Update(current_mouseX, current_mouseY);
  }
}

void MyApp::mouseMove(MouseEvent event) {
  can_draw = true;
}
}  // namespace myapp
