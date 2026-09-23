#include "image.h"

#include <fstream>
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

void ImagePixelDeleter::operator()(unsigned char *ptr) const {
  stbi_image_free(ptr);
}

Image::Image(std::filesystem::path path) : path(path) {
  if (!std::filesystem::exists(path)) {
    throw std::runtime_error("Image file not found: " + path.string());
  }

  std::ifstream file(path, std::ios::binary | std::ios::ate);
  if (!file) {
    throw std::runtime_error("Failed to open file: " + path.string());
  }

  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);
  bytes.resize(static_cast<size_t>(size));
  file.read(reinterpret_cast<char *>(bytes.data()), size);
}

void Image::read_image(void) {
  // Decode from the in-memory bytes; stbi returns a raw buffer we own
  pixels.reset(stbi_load_from_memory(bytes.data(), static_cast<int>(bytes.size()),
                                     &width, &height, &channels, 4));

  if (!pixels) {
    throw std::runtime_error("Failed to decode image");
  }
}
