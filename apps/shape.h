//
// Created by Jacob Rubin on 4/29/20.
//

#ifndef FINALPROJECT_SHAPE_H
#define FINALPROJECT_SHAPE_H
#include <cinder/app/App.h>

#include <string>
#include <vector>

#include "cinder/Shape2d.h"
#include "cinder/gl/gl.h"

enum class ShapeType {
  line,
  scribble,
  rect,
  ellipse,
};

using namespace cinder;
using std::string;
using std::vector;

class Shape {
 public:
  Shape(Color c, ShapeType st, const int& x, const int& y);

  /**
   * Updates the coordinates of the shape. Used when drawing
   * @param current_x the new x coordiante
   * @param current_y the new y coordinate
   */
  void Update(const int& current_x, const int& current_y);

  /**
   * Draws the shape on the screen
   */
  void Display();

  /**
   * FOR TESTING ONLY. Updates the shape coordinates, but does not call
   * cinder::gl::clear
   * @param current_x the new X coordinate
   * @param current_y the new Y coordinate
   */
  void UpdateWithoutClearing(const int& current_x, const int& current_y);


  /**
   * Get the starting x coordinate
   * @return int, the starting x coordinate
   */
  int GetStartX();

  /**
   * Get the ending x coordinate
   * @return int, the ending x coordinate
   */
  int GetEndX();

  /**
   * Get the starting y coordinate
   * @return int, the starting y coordinate
   */
  int GetStartY();

  /**
   * Get the ending y coordinate
   * @return int, the ending y coordinate
   */
  int GetEndY();

 private:
  Color color;
  ShapeType shapetype;
  int start_x;
  int start_y;
  int end_x;
  int end_y;
  Shape2d scribble;
};

#endif  // FINALPROJECT_SHAPE_H
