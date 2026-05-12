#include "iv.h"
#include "stb/stb_image.h"

IV::IV(char *argv[]) : image(Image(argv[1])) {
  thread = std::thread(&Image::read_image, &image);

  SDL_Init(SDL_INIT_VIDEO);
  pwindow =
      SDL_CreateWindow("iv", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       900, 600, SDL_WINDOW_RESIZABLE);
  prenderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_ACCELERATED);

  thread.join();

  ptexture =
      SDL_CreateTexture(prenderer, SDL_PIXELFORMAT_RGBA32,
                        SDL_TEXTUREACCESS_STATIC, image.width, image.height);
  SDL_UpdateTexture(ptexture, NULL, image.pixels, image.width * 4);

  rect = {0, 0, (float)image.width, (float)image.height};

  fit_and_center_image();
}
