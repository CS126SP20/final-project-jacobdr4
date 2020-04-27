//
// Created by Jacob Rubin on 4/26/20.
//

#include "paintcanvas.h"

#include <cinder/app/App.h>

PaintCanvas::PaintCanvas(const int& left, const int& right, const int& top,
                         const int& bottom) {
  left_bound = left;
  right_bound = right;
  top_bound = top;
  bottom_bound = bottom;
}

void PaintCanvas::DrawLine(const int& start_x, const int& start_y, cinder::app::MouseEvent mouseEvent) {

}
