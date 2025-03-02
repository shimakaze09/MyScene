//
// Created by Admin on 18/02/2025.
//

#pragma once

#include "Light.h"

#include <MyGM/normal.h>
#include <MyGM/point.h>
#include <MyGM/rgb.h>
#include <MyGM/vec.h>

namespace My {
class Texture2D;

// EnvLight's radiance = intensity * color * texture(u, v)
struct EnvLight : Light {
  float intensity;
  rgbf color;
  Texture2D* texture;

  rgbf RadianceFactor() const noexcept { return intensity * color; }

  rgbf Radiance(const pointf2& uv) const noexcept;
  rgbf Radiance(const vecf3& dir) const noexcept;

  // radiance, wi, pdf
  std::tuple<rgbf, vecf3, float> Sample() const noexcept;
  float PDF(const vecf3& dir) const noexcept;

  // radiance, wi, pdf
  // assert(n.is_normalized())
  std::tuple<rgbf, vecf3, float> Sample(const normalf& n) const noexcept;
  float PDF(const vecf3& dir, const normalf& n) const noexcept;

  EnvLight(float intensity = 1.f, const rgbf& color = rgbf{1.f, 1.f, 1.f},
           Texture2D* texture = nullptr);

  static void OnRegister();
};
}  // namespace My
