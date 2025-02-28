//
// Created by Admin on 27/02/2025.
//

#include <MyScene/core/Light/EnvLight.h>

#include <MyScene/core/Material/Texture2D.h>

#include "detail/dynamic_reflection/EnvLight.inl"

using namespace My;

EnvLight::EnvLight(float intensity, const rgbf& color, Texture2D* texture)
    : intensity{intensity}, color{color}, texture{texture} {}

rgbf EnvLight::radiance(const pointf2& uv) const noexcept {
  if (!texture)
    return radiance_factor();

  return texture->Sample(uv).to_rgb();
}

void EnvLight::OnRegist() {
  detail::dynamic_reflection::ReflRegist_EnvLight();
}
