#include "iv/iv.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    throw std::runtime_error("Usage: iv <path to image>");
  }

  // Initialize the application
  IV iv(argv);

  // Main app loop
  while (iv.running) {
    iv.wait_event();
    iv.process_event();
    iv.update();
  }

  // Exit cleanly
  iv.kill();
  return 0;
}
