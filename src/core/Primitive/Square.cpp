//
// Created by Admin on 28/02/2025.
//

#pragma once

#include <MyScene/core/Primitive/Square.h>

#include "detail/dynamic_reflection/Square.inl"

using namespace My;

void Square::OnRegister() {
  detail::dynamic_reflection::ReflRegister_Square();
}
