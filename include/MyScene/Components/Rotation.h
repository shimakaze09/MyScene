//
// Created by Admin on 13/03/2025.
//

#pragma once

#include <MyGM/quat.h>

namespace My {
namespace MyScene {
struct Rotation {
  quatf value{quatf::identity()};
};
}  // namespace MyScene
}  // namespace My

#include "details/Rotation_AutoRefl.inl"
