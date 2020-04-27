//
// Created by Jacob Rubin on 4/26/20.
//

#ifndef FINALPROJECT_PAINTCANVAS_H
#define FINALPROJECT_PAINTCANVAS_H
#include <UI.h>
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Utilities.h"
#include <cinder/app/App.h>
#include <vector>

class PaintCanvas {
 public:
  PaintCanvas(const int& left, const int& right, const int& top, const int& bottom);
  int GetMouseX();
  int GetMouseY();
  bool MousePressed();
  void DisplayCanvas();

 private:
  int left_bound;
  int right_bound;
  int top_bound;
  int bottom_bound;

  void DrawLine(const int& start_x, const int& start_y);
};

#endif  // FINALPROJECT_PAINTCANVAS_H
