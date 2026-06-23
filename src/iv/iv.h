#pragma once

#include <SDL2/SDL.h>

#include <cstdint>
#include <mutex>
#include <thread>

#include "../image/image.h"

struct IV {
  Image image;

  SDL_Window *pwindow;
  SDL_Renderer *prenderer;
  SDL_Texture *ptexture;

  SDL_FRect rect;
  int32_t window_w, window_h;

  SDL_Event event;

  bool running = true;
  std::thread thread;
  std::mutex mutex;

  void fit_and_center_image(void);

  // Initialize the application and show image on screen
  IV(char *argv[]);

  // Zoom in towards center of visibility
  void zoom_in(void);
  // Zoom out from center of visibility
  void zoom_out(void);

  void move_left(void);
  void move_right(void);
  void move_up(void);
  void move_down(void);

  void wait_event(void);
  void process_event(void);
  void update(void);

  void kill(void);
};
