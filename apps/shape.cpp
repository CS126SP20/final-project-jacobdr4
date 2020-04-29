//
// Created by Jacob Rubin on 4/29/20.
//

#include "shape.h"
Shape::Shape(Color c, ShapeType st, const int& x, const int& y) {
  color = c;
  shapetype = st;
  start_x = x;
  start_y = y;
  end_x = x;
  end_y = y;
}

void Shape::Update(const int& current_x, const int& current_y) {
  end_x = current_x;
  end_y = current_y;
  cinder::gl::clear();
}

void Shape::Display() {
  if (shapetype == ShapeType::line) {
    cinder::gl::color(color);
    cinder::vec2 xVec = {start_x, start_y};
    cinder::vec2 yVec = {end_x, end_y};
    cinder::gl::drawLine(xVec, yVec);
  }
}
