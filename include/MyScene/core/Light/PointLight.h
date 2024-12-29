//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "Light.h"

namespace My {
struct PointLight : Light {
  // point light's luminance : intensity * color * delta(A)
  float intensity;
  rgbf color;

  PointLight(float intensity = 1.f, const rgbf& color = rgbf{1.f})
      : intensity(intensity), color(color) {}
};
}  // namespace My
