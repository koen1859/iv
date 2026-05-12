#pragma once

#include <cstdint>
#include <filesystem>
#include <vector>

#include "color.h"

struct Image {
  int32_t width, height, channels;
  std::filesystem::path path;
  std::vector<Color> pixels;
  size_t file_size;

  Image(std::filesystem::path path);

  /*Reads an image from the given path and returns a vector of colors.*/
  void read_image(void);
};
