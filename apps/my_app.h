// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_
#include <UI.h>
#include <cinder/app/App.h>

#include <vector>

#include "../include/paint_utils.h"
#include "cinder/Utilities.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/shape2d.h"

using std::vector;
using cinder::app::MouseEvent;
using namespace reza::ui;
using namespace ci;
using namespace ci::app;
using namespace std;

namespace myapp {

class MyApp : public cinder::app::App {
 private:
  SuperCanvasRef mUi;

  ButtonRef line_btn;
  ButtonRef erase_btn;
  ButtonRef draw_btn;
  ButtonRef fill_btn;

  int start_mouseX;
  int start_mouseY;
  int current_mouseX;
  int current_mouseY;

  MultiSliderRef color_slider;
  float red;
  float green;
  float blue;

  Tool tool;
  Shape2d mShape;


  /**
   * Creates the buttons and adds them to the canvas
   */
  void CreateButtons();

  /**
   * Funcitonality to draw a straight line on the screen
   */
  void DrawLine();

  /**
   * Functionality to scribble on the screen
   */
  void DrawScribble();

  /**
   * Creates the color slider so the user can select a color to draw with
   */
  void CreateColorSlider();

 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void cleanup() override;
  fs::path getSaveLoadPath();

  void mouseDown(MouseEvent event) override;
  void mouseUp(MouseEvent event) override ;
  void mouseMove(MouseEvent event) override;
  void mouseDrag(MouseEvent event) override;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
