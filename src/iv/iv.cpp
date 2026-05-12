#include "iv.h"

IV::IV(char *argv[]) : image(Image(argv[1])) {
  SDL_Init(SDL_INIT_VIDEO);
  pwindow =
      SDL_CreateWindow("iv", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       image.width, image.height, SDL_WINDOW_RESIZABLE);
  prenderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_ACCELERATED);
  ptexture =
      SDL_CreateTexture(prenderer, SDL_PIXELFORMAT_RGB24,
                        SDL_TEXTUREACCESS_STATIC, image.width, image.height);
  SDL_UpdateTexture(ptexture, NULL, image.pixels.data(),
                    image.width * sizeof(Color));

  rect = {0, 0, (float)image.width, (float)image.height};

  fit_and_center_image();
}
