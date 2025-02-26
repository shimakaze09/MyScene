//
// Created by Admin on 26/02/2025.
//

#pragma once

#include <string>

#include <MyBL/Image.h>
#include <MyGM/point.h>

namespace My {
class Texture2D {
 public:
  enum class WrapMode { Clamp, Repeat, Mirror };
  enum class Sample { Nearest, Linear };

  Texture2D() = default;
  Texture2D(const std::string& path);
  virtual ~Texture2D() = default;  // virtual -> vtable -> typeid

  bool inv_u{false};
  bool inv_v{false};
  bool swap_uv{false};
  WrapMode wrap_u{WrapMode::Clamp};
  WrapMode wrap_v{WrapMode::Clamp};
  Read<Texture2D, std::string> path;

  void SetPath(const std::string& path);
  rgbaf Sample(pointf2 uv);

 private:
  Image* img{nullptr};
};
}  // namespace My
