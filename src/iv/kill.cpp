#include "iv.h"

void IV::kill(void) {
  SDL_DestroyTexture(ptexture);
  SDL_DestroyRenderer(prenderer);
  SDL_DestroyWindow(pwindow);
  SDL_Quit();
}
