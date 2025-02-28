//
// Created by Admin on 28/02/2025.
//

#pragma once

#include <MyScene/core/Light/DirLight.h>

#include "detail/dynamic_reflection/DirLight.inl"

using namespace My;

DirLight::DirLight(float intensity, const rgbf& color)
    : intensity(intensity), color(color) {}

void DirLight::OnRegist() {
  detail::dynamic_reflection::ReflRegist_DirLight();
}
