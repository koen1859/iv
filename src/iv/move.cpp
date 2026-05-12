#include "iv.h"

void IV::move_left(void) {
  rect.x += 10 * std::exp((float)image.width / rect.w);
}
void IV::move_right(void) {
  rect.x -= 10 * std::exp((float)image.width / rect.w);
}
void IV::move_up(void) { rect.y += 10 * std::exp((float)image.width / rect.w); }
void IV::move_down(void) {
  rect.y -= 10 * std::exp((float)image.width / rect.w);
}
