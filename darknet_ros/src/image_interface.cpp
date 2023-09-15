/*
 * image_interface.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: Marko Bjelonic
 *   Institute: ETH Zurich, Robotic Systems Lab
 */

#include "darknet_ros/image_interface.hpp"

static float get_pixel(image m, int x, int y, int c) {
  assert(x < m.w && y < m.h && c < m.c);
  return m.data[c * m.h * m.w + y * m.w + x];
}

#ifdef OPENCV
void generate_image(image p, cv::Mat& disp) {
  int x, y, k;
  if (p.c == 3) rgbgr_image(p);
  // normalize_image(copy);

  int step = disp.step;
  for (y = 0; y < p.h; ++y) {
    for (x = 0; x < p.w; ++x) {
      for (k = 0; k < p.c; ++k) {
        disp.data[y * step + x * p.c + k] = (unsigned char)(get_pixel(p, x, y, k) * 255);
      }
    }
  }
}
#endif
