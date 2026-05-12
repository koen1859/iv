#include "iv.h"
#include <SDL_keycode.h>

void IV::wait_event(void) { SDL_WaitEvent(&event); }

void IV::process_event(void) {
  switch (event.type) {
  case SDL_QUIT:
    running = false;
    break;

  case SDL_WINDOWEVENT:
    if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
      fit_and_center_image();
    }
    break;

  case SDL_KEYDOWN:
    switch (event.key.keysym.sym) {
    case SDLK_EQUALS:
      zoom_in();
      break;

    case SDLK_MINUS:
      zoom_out();
      break;

    case SDLK_a:
      fit_and_center_image();
      break;

    case SDLK_h:
      move_left();
      break;

    case SDLK_j:
      move_down();
      break;

    case SDLK_k:
      move_up();
      break;

    case SDLK_l:
      move_right();
      break;

    case SDLK_q:
      running = false;
      break;
    }
    break;
  }
  update();
}
