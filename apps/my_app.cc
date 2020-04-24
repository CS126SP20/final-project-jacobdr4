// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <ciButton.h>

namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() {}

void MyApp::setup() {
  SetUpButtons();
}

void MyApp::update() {}

void MyApp::draw() {}

void MyApp::keyDown(KeyEvent event) {}

void MyApp::SetButtonCoordinates() {
  int screen_width = cinder::app::getWindowWidth();

  for (int x = 0; x < kNumButtons; x++) {
    button_x.push_back(((screen_width / kNumButtons + 2) * x) +
                       (screen_width / kNumButtons + 2));
  }
}

void MyApp::SetUpButtons() {
  SetButtonCoordinates();
  int button_size = 50;
  line_button.setRect(button_x[0], button_size, button_x[0] + button_size, button_size * 2);
  erase_button.setRect(button_x[1], button_size, button_x[1] + button_size, button_size * 2);
  fill_button.setRect(button_x[2], button_size, button_x[2] + button_size, button_size * 2);
  draw_button.setRect(button_x[3], button_size, button_x[3] + button_size, button_size * 2);
}

}
// namespace myapp