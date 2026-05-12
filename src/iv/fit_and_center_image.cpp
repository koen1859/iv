#include "iv.h"

void IV::fit_and_center_image(void) {
  SDL_GetRendererOutputSize(prenderer, &window_w, &window_h);
  float scale_x = (float)window_w / (float)image.width;
  float scale_y = (float)window_h / (float)image.height;

  float final_scale = std::min(scale_x, scale_y);

  rect.w = image.width * final_scale;
  rect.h = image.height * final_scale;

  rect.x = (window_w - rect.w) / 2.0f;
  rect.y = (window_h - rect.h) / 2.0f;
}
