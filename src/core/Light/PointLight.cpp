//
// Created by Admin on 28/02/2025.
//

#pragma once

#include <MyScene/core/Light/PointLight.h>

#include "detail/dynamic_reflection/PointLight.inl"

using namespace My;

PointLight::PointLight(float intensity, const rgbf& color)
    : intensity(intensity), color(color) {}

void PointLight::OnRegist() {
  detail::dynamic_reflection::ReflRegist_PointLight();
}
