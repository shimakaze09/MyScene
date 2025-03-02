//
// Created by Admin on 18/02/2025.
//

#pragma once

#include "Light.h"

#include <MyGM/rgb.h>

namespace My {
// DirLight's radiance : intensity * color * delta(w)
struct DirLight : Light {
  [[range("0,")]]
  float intensity;
  rgbf color;

  rgbf Radiance() const noexcept { return intensity * color; }

  DirLight(float intensity = 1.f, const rgbf& color = rgbf{1.f, 1.f, 1.f});

  static void OnRegister();
};
}  // namespace My
