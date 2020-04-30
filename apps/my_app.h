// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_
#include <UI.h>
#include <cinder/app/App.h>

#include <iostream>
#include <vector>

#include "cinder/Utilities.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/shape2d.h"
#include "shape.h"

using cinder::app::MouseEvent;
using std::vector;
using namespace reza::ui;
using namespace ci;
using namespace ci::app;
using namespace std;

enum class Tool {
  line,
  scribble,
  rect,
  fill,
  clear,
};

namespace myapp {

class MyApp : public cinder::app::App {
 private:
  SuperCanvasRef mUi;

  RadioRef tool_radio;

  int start_mouseX;
  int start_mouseY;
  int current_mouseX;
  int current_mouseY;

  MultiSliderRef color_slider;
  float red;
  float green;
  float blue;

  Color background_color;

  Shape2d mShape;
  vector<Shape> shapes;

  static Tool tool;

  /**
   * Creates the buttons and adds them to the canvas
   */
  void CreateButtons();

  /**
   * Creates the color slider so the user can select a color to draw with
   */
  void CreateColorSlider();

  /**
   * The display settings for the color slider
   */
  void ColorSliderSettings();

  /**
   * Sets the tool variable to the proper tool based on the radio selection
   * @param name The name of the tool
   * @param value True is radio button with the above name is selected, false if otherwise
   */
  static void OnButtonPress(string name, bool value);

  /**
   * Clears the drawing board
   */
  void Clear();

  /**
   * Sets the color of the background to the color on the sliders
   */
  void SetBackgroundColor();

 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void cleanup() override;
  fs::path getSaveLoadPath();

  void mouseDown(MouseEvent event) override;
  void mouseUp(MouseEvent event) override;
  void mouseMove(MouseEvent event) override;
  void mouseDrag(MouseEvent event) override;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_