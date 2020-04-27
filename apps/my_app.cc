// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>

namespace myapp {

using cinder::app::KeyEvent;
using cinder::app::MouseEvent;
using cinder::app::Event;


MyApp::MyApp() {

}

void MyApp::setup() {
  mUi = SuperCanvas::create( "Pixel Paint" );
  CreateButtons();
  mUi->autoSizeToFitSubviews();
  mUi->load( getSaveLoadPath() );

  //std::cout << mUi->getX();
  //std::cout << mUi->getY();
  //std::cout << mUi->getWidth();
  //std::cout << "\n";
  //std::cout << mUi->getHeight();
}

void MyApp::update() {

}

void MyApp::draw() {
  cinder::gl::clear();
  DrawLine();
}

void MyApp::keyDown(KeyEvent event) {}


void MyApp::cleanup()
{
  mUi->save( getSaveLoadPath() );
}

fs::path MyApp::getSaveLoadPath()
{
  fs::path path = getAssetPath( "" );
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

void MyApp::mouseDown(MouseEvent event) {
  start_mouseX = event.getX();
  start_mouseY = event.getY();
}

void MyApp::mouseUp(MouseEvent event) {

}

void MyApp::mouseDrag(MouseEvent event) {
  current_mouseX = event.getX();
  current_mouseY = event.getY();
}

void MyApp::mouseMove(MouseEvent event) {

}

}
// namespace myapp