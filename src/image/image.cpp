#include "image.h"
#include <filesystem>
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

Image::Image(std::filesystem::path path)
    : path(path), file_size(0), width(0), height(0), channels(0),
      pixels(nullptr) {
  if (std::filesystem::exists(path)) {
    file_size = std::filesystem::file_size(path);
  }
}

void Image::read_image(void) {
  // File does not exist: fail
  if (!std::filesystem::exists(path)) {
    throw std::runtime_error("Image file not found: " + path.string());
  }

  // stbi_load returns a raw C-style array
  pixels = stbi_load(path.string().c_str(), &width, &height, &channels, 4);

  if (!pixels) {
    throw std::runtime_error("Failed to decode image");
  }
}
