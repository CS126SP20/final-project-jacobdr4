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
};

using namespace cinder;
class Shape {
 public:
  Shape(Color c, ShapeType st, const int& x, const int& y);
  void Update(const int& current_x, const int& current_y);
  void Display();

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
