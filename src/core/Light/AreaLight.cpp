//
// Created by Admin on 27/02/2025.
//

#include <MyScene/core/Light/AreaLight.h>

#include <MyScene/core/Material/Texture2D.h>

using namespace My;

rgbf AreaLight::radiance(const pointf2& uv) const noexcept {
  if (!texture)
    return radiance_factor();

  return texture->Sample(uv).to_rgb();
}