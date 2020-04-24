// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_
#include <cocButton.h>
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Utilities.h"
#include <cinder/app/App.h>
#include <vector>

using std::vector;
namespace myapp {

class MyApp : public cinder::app::App {
 private:
  const int kNumButtons = 4;
  vector<int> button_x;

  coc::ciButton line_button;
  coc::ciButton fill_button;
  coc::ciButton erase_button;
  coc::ciButton draw_button;


  void SetButtonCoordinates();
  void SetUpButtons();


 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
