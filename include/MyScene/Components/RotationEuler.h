//
// Created by Admin on 13/03/2025.
//

#pragma once

#include <MyGM/euler.h>

namespace My {
namespace MyScene {
struct RotationEuler {
  eulerf value{0.f};
};
}  // namespace MyScene
}  // namespace My

#include "details/RotationEuler_AutoRefl.inl"
