//
// Created by Admin on 27/02/2025.
//

#include <MyScene/core/Light/AreaLight.h>

#include <MyScene/core/Material/Texture2D.h>

#include "detail/dynamic_reflection/AreaLight.inl"

using namespace My;

rgbf AreaLight::Radiance(const pointf2& uv) const noexcept {
  if (!texture)
    return RadianceFactor();

  return texture->Sample(uv).to_rgb();
}

void AreaLight::OnRegister() {
  detail::dynamic_reflection::ReflRegister_AreaLight();
}
