//
// Created by Jacob Rubin on 4/26/20.
//

#ifndef FINALPROJECT_PAINTCANVAS_H
#define FINALPROJECT_PAINTCANVAS_H

#include "../../../include/cinder/app/MouseEvent.h"
class PaintCanvas {
 public:
  PaintCanvas(const int& left, const int& right, const int& top, const int& bottom);
  void DisplayCanvas();

 private:
  int left_bound;
  int right_bound;
  int top_bound;
  int bottom_bound;

  void DrawLine(const int& start_x, const int& start_y, cinder::app::MouseEvent mouseEvent);
};

#endif  // FINALPROJECT_PAINTCANVAS_H
