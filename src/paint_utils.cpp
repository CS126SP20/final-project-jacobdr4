//
// Created by Jacob Rubin on 4/26/20.
//

#include "paint_utils.h"

#include <cinder/app/App.h>

PaintUtils::PaintUtils(const int& left, const int& right, const int& top,
                         const int& bottom) {
  left_bound = left;
  right_bound = right;
  top_bound = top;
  bottom_bound = bottom;
}
