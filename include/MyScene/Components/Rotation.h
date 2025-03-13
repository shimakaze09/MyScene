//
// Created by Admin on 13/03/2025.
//

#pragma once

#include <MyGM/quat.h>

namespace My::MyScene {
struct Rotation {
  quatf value{quatf::identity()};
};
}  // namespace My::MyScene

#include "details/Rotation_AutoRefl.inl"
