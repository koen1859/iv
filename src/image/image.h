#pragma once

#include <filesystem>

struct Image {
  std::filesystem::path path;
  uint64_t file_size;
  int width, height, channels;

  // Use a unique_ptr with a custom deleter to manage raw pixel data
  unsigned char *pixels;

  Image(std::filesystem::path path);

  // This function will handle loading the image data
  void read_image(void);
};
