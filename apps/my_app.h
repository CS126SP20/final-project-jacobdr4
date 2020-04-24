// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_
#include <UI.h>
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Utilities.h"
#include <cinder/app/App.h>
#include <vector>

using std::vector;
using namespace reza::ui;
using namespace ci;
using namespace ci::app;
using namespace std;

namespace myapp {

class MyApp : public cinder::app::App {
 private:
  const int kNumButtons = 4;
  vector<int> button_x;
  SuperCanvasRef mUi;


 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void cleanup() override;
  fs::path getSaveLoadPath();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
