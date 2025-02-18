//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "Light.h"

#include <MyGM/rgb.h>

namespace My {
// point light's luminance : intensity * color * delta(A)
struct PointLight : Light {
  float intensity;
  rgbf color;

  PointLight(float intensity = 1.f, const rgbf& color = rgbf{1.f})
      : intensity(intensity), color(color) {}
};
}  // namespace My
