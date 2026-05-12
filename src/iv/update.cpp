#include "iv.h"

void IV::update(void) {
  SDL_SetRenderDrawColor(prenderer, 20, 20, 20, 255);
  SDL_RenderClear(prenderer);
  SDL_RenderCopyF(prenderer, ptexture, NULL, &rect);
  SDL_RenderPresent(prenderer);
}
