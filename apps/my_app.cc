// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>

namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() {}

void MyApp::setup() {
  mUi = SuperCanvas::create( "basic" );
  mUi->addButton("Line", true);
  mUi->addButton("Draw", true);
  mUi->addButton("Erase", true);
  mUi->addButton("Fill", true);
  mUi->autoSizeToFitSubviews();
  mUi->load( getSaveLoadPath() );
}

void MyApp::update() {

}

void MyApp::draw() {

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

}
// namespace myapp