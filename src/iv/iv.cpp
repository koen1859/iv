#include "iv.h"

#include <SDL_error.h>

#include <cstdio>
#include <exception>
#include <stdexcept>

IV::IV(char *argv[]) : image(Image(argv[1])) {
  // Kick off the decode as early as possible so it overlaps with the SDL
  // initialization below; the texture is uploaded from update() once it's done.
  thread = std::thread([this]() {
    try {
      image.read_image();
    } catch (std::exception &e) {
      std::fprintf(stderr, "iv: %s\n", e.what());
      running = false;
      return;
    }
    loaded = true;
  });

  try {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      throw std::runtime_error(std::string("SDL_Init failed: ") +
                               SDL_GetError());
    }

    pwindow =
        SDL_CreateWindow("iv", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         900, 600, SDL_WINDOW_RESIZABLE);
    if (!pwindow) {
      throw std::runtime_error(std::string("SDL_CreateWindow failed: ") +
                               SDL_GetError());
    }

    prenderer =
        SDL_CreateRenderer(pwindow, -1,
                           SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!prenderer) {
      prenderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_ACCELERATED);
    }
    if (!prenderer) {
      throw std::runtime_error(std::string("SDL_CreateRenderer failed: ") +
                               SDL_GetError());
    }
  } catch (...) {
    // Don't let std::thread's destructor terminate() a running decode
    if (thread.joinable()) {
      thread.join();
    }
    throw;
  }

  // Show the window immediately with a placeholder frame.
  update();
}