// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>

namespace myapp {

using cinder::app::Event;
using cinder::app::KeyEvent;
using cinder::app::MouseEvent;
using namespace std;

Tool MyApp::tool;

MyApp::MyApp() { tool = Tool::line; }

void MyApp::setup() {
  mUi = SuperCanvas::create("Pixel Paint");
  CreateButtons();
  CreateColorSlider();
  mUi->autoSizeToFitSubviews();
  mUi->load(getSaveLoadPath());
}

void MyApp::update() {
  color_slider->setColorOutline(ColorA(red, green, blue));
  color_slider->setColorOutlineHighlight(ColorA(red, green, blue));
  color_slider->setColorFillHighlight(ColorA(red, green, blue));
  color_slider->setDrawBoundsOutline(false);
}

void MyApp::draw() {
  if (tool == Tool::clear) {
    Clear();
  }
}

void MyApp::keyDown(KeyEvent event) {}

void MyApp::cleanup() { mUi->save(getSaveLoadPath()); }

fs::path MyApp::getSaveLoadPath() {
  fs::path path = getAssetPath("");
  path += "/" + mUi->getName() + ".json";
  return path;
}

void MyApp::CreateButtons() {
  vector<std::string> tools = {"Line", "Scribble", "Rect", "Fill", "Clear"};
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
  slider_data.push_back(MultiSlider::Data("GREEN", &blue, 0.0, 1.0));
  slider_data.push_back(MultiSlider::Data("BLUE", &green, 0.0, 1.0));

  color_slider = MultiSlider::create("Paint Color", slider_data,
                                     MultiSlider::Format().crossFader());
  mUi->addSubViewDown(color_slider, Alignment::LEFT);
}

void MyApp::DrawLine() {
  vec2 start_pos = {start_mouseX, start_mouseY};
  vec2 end_pos = {current_mouseX, current_mouseY};
  cinder::gl::color(Color(red, green, blue));
  cinder::gl::drawLine(start_pos, end_pos);
}

void MyApp::DrawScribble() {
  cinder::gl::color(Color(red, green, blue));
  cinder::gl::draw(mShape);
}

void MyApp::DrawRect() {
  cinder::gl::color(Color(red, green, blue));
  cinder::gl::drawStrokedRect(
      Rectf(start_mouseX, start_mouseY, current_mouseX, current_mouseY));
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
  } else {
    tool = Tool::clear;
  }
}

void MyApp::mouseDown(MouseEvent event) {
  if (tool == Tool::line) {
    start_mouseX = event.getX();
    start_mouseY = event.getY();

    shapes.push_back(Shape(Color(red, green, blue),ShapeType::line, start_mouseX, start_mouseY));
  }
}

void MyApp::mouseUp(MouseEvent event) {

}

void MyApp::mouseDrag(MouseEvent event) {
  if (tool == Tool::line) {
    current_mouseX = event.getX();
    current_mouseY = event.getY();
    shapes[shapes.size() - 1].Update(current_mouseX, current_mouseY);

    for (Shape s: shapes) {
      s.Display();
    }
  }
}

void MyApp::mouseMove(MouseEvent event) {}
}  // namespace myapp
