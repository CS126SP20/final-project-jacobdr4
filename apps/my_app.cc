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
  mUi->autoSizeToFitSubviews();
  mUi->load(getSaveLoadPath());
}

void MyApp::update() {}

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

void MyApp::DrawLine() {
  vec2 start_pos = {start_mouseX, start_mouseY};
  vec2 end_pos = {current_mouseX, current_mouseY};
  cinder::gl::color(Color(1, 1, 1));
  cinder::gl::drawLine(start_pos, end_pos);
}

void MyApp::DrawScribble() {
  cinder::gl::color(Color(1, 1, 1));
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

}  // namespace myapp
   // namespace myapp