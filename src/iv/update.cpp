#include "iv.h"

void IV::update(void) {
  SDL_SetRenderDrawColor(prenderer, 32, 32, 32, 255);
  SDL_RenderClear(prenderer);
  SDL_RenderCopyF(prenderer, ptexture, NULL, &rect);
  SDL_RenderPresent(prenderer);
}
