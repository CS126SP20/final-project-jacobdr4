// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>

namespace myapp {

using cinder::app::Event;
using cinder::app::KeyEvent;
using cinder::app::MouseEvent;

MyApp::MyApp() {}

void MyApp::setup() {
  tool = Tool::scribble;
  mUi = SuperCanvas::create("Pixel Paint");
  CreateButtons();
  CreateColorSlider();
  mUi->autoSizeToFitSubviews();
  mUi->load(getSaveLoadPath());
}

void MyApp::update() {
  color_slider->setColorOutline(ColorA(red, green, blue) );
  color_slider->setColorOutlineHighlight(ColorA(red, green, blue));
  color_slider->setColorFillHighlight(ColorA(red, green, blue));
  color_slider->setDrawBoundsOutline(false);
}

void MyApp::draw() {
  if (tool == Tool::line) {
    cinder::gl::clear();
    DrawLine();
  }

  if (tool == Tool::scribble) {
    DrawScribble();
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
  line_btn = Button::create("Line", false);
  mUi->addSubViewDown(line_btn, Alignment::LEFT);

  erase_btn = Button::create("Erase", false);
  mUi->addSubViewDown(erase_btn, Alignment::LEFT);

  draw_btn = Button::create("Draw", false);
  mUi->addSubViewDown(draw_btn, Alignment::LEFT);

  fill_btn = Button::create("Fill", false);
  mUi->addSubViewDown(fill_btn, Alignment::LEFT);
}

void MyApp::CreateColorSlider() {
  red = 0.0;
  blue = 0.0;
  green = 0.0;
  vector<MultiSlider::Data> slider_data;
  slider_data.push_back(MultiSlider::Data( "RED", &red ,0.0, 1.0 ));
  slider_data.push_back(MultiSlider::Data( "GREEN", &blue, 0.0, 1.0));
  slider_data.push_back(MultiSlider::Data( "BLUE", &green, 0.0, 1.0 ));

   color_slider = MultiSlider::create("COLOR", slider_data, MultiSlider::Format().crossFader());
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

void MyApp::mouseDown(MouseEvent event) {
  if (tool == Tool::line) {
    start_mouseX = event.getX();
    start_mouseY = event.getY();
    current_mouseX = event.getX();
    current_mouseY = event.getY();
  }

  if (tool == Tool::scribble) {
    mShape.moveTo( event.getPos() );
  }
}

void MyApp::mouseUp(MouseEvent event) {}

void MyApp::mouseDrag(MouseEvent event) {
  if (tool == Tool::line) {
    current_mouseX = event.getX();
    current_mouseY = event.getY();
  }

  if (tool == Tool::scribble) {
    mShape.lineTo( event.getPos() );
  }
}

void MyApp::mouseMove(MouseEvent event) {}

}
// namespace myapp
