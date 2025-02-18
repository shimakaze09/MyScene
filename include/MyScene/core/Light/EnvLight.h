//
// Created by Admin on 18/02/2025.
//

#pragma once

#include "Light.h"

#include "../Resource/Image.h"

#include <MyGM/rgb.h>

namespace My {
// EnvLight's radiance = intensity * color * texture(u, v)
struct EnvLight : Light {
  float intensity;
  rgbf color;
  Image* texture;

  EnvLight(float intensity = 1.f, const rgbf& color = rgbf{1.f},
           Image* texture = nullptr)
      : intensity{intensity}, color{color}, texture{texture} {}
};
}  // namespace My
