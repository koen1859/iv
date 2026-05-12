#include "iv.h"

void IV::kill(void) {
  if (thread.joinable()) {
    thread.join();
  }
  SDL_DestroyTexture(ptexture);
  SDL_DestroyRenderer(prenderer);
  SDL_DestroyWindow(pwindow);
  SDL_Quit();
}
