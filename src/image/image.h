#pragma once

#include <filesystem>
#include <memory>
#include <vector>

// Function object that frees stb_image buffers
struct ImagePixelDeleter {
  void operator()(unsigned char *ptr) const;
};

struct Image {
  std::filesystem::path path;
  int width = 0;
  int height = 0;
  int channels = 0;

  // Raw file bytes, loaded once up front
  std::vector<unsigned char> bytes;

  // Decoded RGBA pixels, owned via unique_ptr
  std::unique_ptr<unsigned char, ImagePixelDeleter> pixels;

  // Loads the file bytes from disk
  Image(std::filesystem::path path);

  // Decodes bytes into pixels (may be called on a worker thread)
  void read_image(void);
};
