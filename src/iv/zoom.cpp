#include "iv.h"

void IV::zoom_in(void) {
  // Center of visible viewport
  float viewport_center_x = window_w / 2.0;
  float viewport_center_y = window_h / 2.0;

  // Convert viewport center to image coordinates
  float image_center_x = (viewport_center_x - rect.x) / rect.w * image.width;
  float image_center_y = (viewport_center_y - rect.y) / rect.h * image.height;

  rect.w *= 1.1;
  rect.h *= 1.1;

  rect.x = viewport_center_x - (image_center_x / image.width) * rect.w;
  rect.y = viewport_center_y - (image_center_y / image.height) * rect.h;
}

void IV::zoom_out(void) {
  // Center of visible viewport
  float viewport_center_x = window_w / 2.0;
  float viewport_center_y = window_h / 2.0;

  // Convert viewport center to image coordinates
  float image_center_x = (viewport_center_x - rect.x) / rect.w * image.width;
  float image_center_y = (viewport_center_y - rect.y) / rect.h * image.height;

  rect.w /= 1.1;
  rect.h /= 1.1;

  rect.x = viewport_center_x - (image_center_x / image.width) * rect.w;
  rect.y = viewport_center_y - (image_center_y / image.height) * rect.h;
}
