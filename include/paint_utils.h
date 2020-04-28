//
// Created by Jacob Rubin on 4/26/20.
//

#ifndef FINALPROJECT_PAINT_UTILS_H
#define FINALPROJECT_PAINT_UTILS_H

enum class Tool {
  none,
  line,
  scribble,
  rect,
};

class PaintUtils {
 public:
  PaintUtils(const int& left, const int& right, const int& top, const int& bottom);
  void DisplayCanvas();

 private:
  int left_bound;
  int right_bound;
  int top_bound;
  int bottom_bound;

};

#endif  // FINALPROJECT_PAINT_UTILS_H
