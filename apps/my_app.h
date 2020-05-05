// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_
#include <UI.h>
#include <cinder/app/App.h>

#include <iostream>

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
  ellipse,
  fill,
  clear,
  save,
  load,
  undo,
};

namespace myapp {

class MyApp : public cinder::app::App {
 private:
  SuperCanvasRef mUi;

  RadioRef radio;

  int start_mouseX;
  int start_mouseY;
  int current_mouseX;
  int current_mouseY;

  MultiSliderRef color_slider;
  float red;
  float green;
  float blue;

  Color background_color;
  Color saved_background_color;

  vector<Shape> shapes;
  vector<Shape> saved_shapes;

  static Tool tool;

  bool can_draw;

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
   * Sets the color of the background to the color on the sliders
   */
  void SetBackgroundColor();

  /**
   * Saves the shape array and background color to saved_shapes and
   * saved_background color respectivally
   */
  void SaveData();

  /**
   * Imports the data from saved_shapes and
   * saved_background to set the
   */
  void LoadData();

  /**
   * Deletes the last element in the vector shapes, acting as an undo command in deleting the
   * last shape drawn
   */
  void Undo();

  /**
   * Returns the corresponding ShapeType enum based on what tool is selected
   * @return a ShapeType enum
   */
  ShapeType GetShapeTypeFromTool();

  /**
   * Detects if the mouse is in the drawing bounds, aka not in the UI part
   * @param mousex the x coordinate of the mouse
   * @param mousey the y coordinate of the mouse
   * @return true if the mouse is outside the UI/in the drawing bounds, false if otherwise
   */
  bool MouseInBounds(const int& mousex, const int& mousey);

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