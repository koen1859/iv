#pragma once

#include <SDL2/SDL.h>
#include <SDL_events.h>
#include <SDL_keycode.h>
#include <SDL_pixels.h>
#include <SDL_render.h>

#include <atomic>
#include <cstdint>
#include <thread>

#include "../image/image.h"

struct IV {
  Image image;

  SDL_Window *pwindow = nullptr;
  SDL_Renderer *prenderer = nullptr;
  SDL_Texture *ptexture = nullptr;

  SDL_FRect rect;
  int32_t window_w, window_h;

  SDL_Event event;

  std::atomic<bool> running = true;

  // Set once the decode thread has finished loading pixels
  std::atomic<bool> loaded = false;

  std::thread thread;

  // True when the view changed and a fresh frame should be rendered
  bool dirty = true;

  void fit_and_center_image(void);

  // Creates the texture (if not already created) once decoding has finished
  bool load_texture(void);

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
