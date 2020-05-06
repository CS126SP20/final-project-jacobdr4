//
// Created by Jacob Rubin on 4/29/20.
//

#ifndef FINALPROJECT_SHAPE_H
#define FINALPROJECT_SHAPE_H
#include "string"
#include "vector"
#include "../../../include/cinder/Shape2d.h"
#include "../../../include/cinder/app/App.h"
#include "../../../include/cinder/gl/gl.h"
#include "../../../include/cinder/svg/Svg.h"

enum class ShapeType {
  line,
  scribble,
  rect,
  ellipse,
  none,
};

using namespace cinder;
using std::string;
using std::vector;

class Shape {
 public:
  /**
   * A single shape that the user can draw, and to be displayed on the screen
   * @param get_color The color of the shape
   * @param get_shapetype The type of shape, from the ShapeType enum
   * @param startx The starting x coordinate of the shape
   * @param starty The starting y coordinate of the shape
   */
  Shape(const Color& get_color, const ShapeType& get_shapetype,
        const int& startx, const int& starty);

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
   * Updates the shape coordinates, but does not call
   * cinder::gl::clear. Used only for testing
   * @param current_x the new X coordinate
   * @param current_y the new Y coordinate
   */
  void UpdateWithoutClearing(const int& current_x, const int& current_y);

  /**
   * Get the ending x coordinate. Used only for testing.
   * @return int, the ending x coordinate
   */
  int GetEndX();

  /**
   * Get the ending y coordinate. Used only for testing
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
