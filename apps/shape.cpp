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

  if (shapetype == ShapeType::scribble) {
    scribble.moveTo(start_x, start_y);
  }
}

void Shape::Update(const int& current_x, const int& current_y) {
  end_x = current_x;
  end_y = current_y;

  if (shapetype == ShapeType::scribble) {
    scribble.lineTo(end_x, end_y);
  }

  cinder::gl::clear();
}

void Shape::Display() {
  cinder::vec2 start_vec = {start_x, start_y};
  cinder::vec2 end_vec = {end_x, end_y};
  cinder::gl::color(color);

  if (shapetype == ShapeType::line) {
    cinder::gl::drawLine(start_vec, end_vec);
  }

  if(shapetype == ShapeType::rect) {
    cinder::gl::drawStrokedRect(Rectf(start_vec, end_vec));
  }

  if (shapetype == ShapeType::scribble) {
    cinder::gl::draw(scribble);
  }
}
