//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "Material.h"

namespace My {
struct Diffuse : Material {
  rgbf albedo;

  Diffuse(const rgbf& albedo = rgbf{1.f}) : albedo(albedo) {}
};
}  // namespace My
