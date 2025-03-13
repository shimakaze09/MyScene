//
// Created by Admin on 13/03/2025.
//

#pragma once

#include <MyGM/transform.h>

namespace My {
namespace MyScene {
struct LocalToParent {
  transformf value{transformf::eye()};
};
}  // namespace MyScene
}  // namespace My

#include "details/LocalToParent_AutoRefl.inl"
