//
// Created by Admin on 13/03/2025.
//

#pragma once

#include <MyGM/transform.h>

namespace My::MyScene {
struct LocalToWorld {
  transformf value{transformf::eye()};
};
}  // namespace My::MyScene

#include "details/LocalToWorld_AutoRefl.inl"
