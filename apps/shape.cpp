//
// Created by Jacob Rubin on 4/29/20.
//

#include "shape.h"
Shape::Shape(const Color& get_color, const ShapeType& get_shapetype,
             const int& startx, const int& starty) {
  color = get_color;
  shapetype = get_shapetype;
  start_x = startx;
  start_y = starty;
  end_x = startx;
  end_y = starty;

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

  if (shapetype == ShapeType::rect) {
    cinder::gl::drawStrokedRect(Rectf(start_vec, end_vec));
  }

  if (shapetype == ShapeType::ellipse) {
    int center_x = (end_x + start_x) / 2;
    int center_y = (end_y + start_y) / 2;
    int radius_x = (abs(center_x - end_x));
    int radius_y = (abs(center_y - end_y));
    cinder::gl::drawStrokedEllipse(vec2(center_x, center_y), radius_x,
                                   radius_y);
  }

  if (shapetype == ShapeType::scribble) {
    cinder::gl::draw(scribble);
  }
}

void Shape::UpdateWithoutClearing(const int& current_x, const int& current_y) {
  end_x = current_x;
  end_y = current_y;

  if (shapetype == ShapeType::scribble) {
    scribble.lineTo(end_x, end_y);
  }
}

int Shape::GetEndX() { return end_x; }

int Shape::GetEndY() { return end_y; }
