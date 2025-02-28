//
// Created by Admin on 28/02/2025.
//

#pragma once

#include <MyScene/core/Primitive/Sphere.h>

#include "detail/dynamic_reflection/Sphere.inl"

using namespace My;

void Sphere::OnRegist() {
  detail::dynamic_reflection::ReflRegist_Sphere();
}
