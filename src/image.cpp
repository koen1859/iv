#include "image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

Image::Image(std::filesystem::path path) : path(path) { read_image(); }

void Image::read_image(void) {
  // File does not exist: fail
  if (!std::filesystem::exists(path)) {
    throw std::runtime_error("Image file not found: " + path.string());
  }

  unsigned char *data =
      stbi_load(path.string().c_str(), &width, &height, &channels, 3);

  if (!data) {
    throw std::runtime_error("Failed to decode PNG");
  }

  pixels.reserve(width * height);

  for (int i = 0; i < width * height * 3; i += 3) {
    pixels.push_back({data[i], data[i + 1], data[i + 2]});
  }

  stbi_image_free(data);
}
