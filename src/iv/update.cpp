#include "iv.h"

bool IV::load_texture(void) {
  if (ptexture || !loaded) {
    return false;
  }

  ptexture =
      SDL_CreateTexture(prenderer, SDL_PIXELFORMAT_RGBA32,
                        SDL_TEXTUREACCESS_STATIC, image.width, image.height);
  if (!ptexture) {
    return false;
  }
  SDL_UpdateTexture(ptexture, NULL, image.pixels.get(), image.width * 4);

  rect = {0, 0, (float)image.width, (float)image.height};
  fit_and_center_image();
  return true;
}

void IV::update(void) {
  bool new_texture = load_texture();
  if (!dirty && !new_texture) {
    return;
  }
  dirty = false;

  SDL_SetRenderDrawColor(prenderer, 32, 32, 32, 255);
  SDL_RenderClear(prenderer);
  if (ptexture) {
    SDL_RenderCopyF(prenderer, ptexture, NULL, &rect);
  }
  SDL_RenderPresent(prenderer);
}
