//
// Created by Admin on 13/03/2025.
//

#pragma once

#include <MyGM/transform.h>

namespace My::MyScene {
struct WorldToLocal {
  transformf value{transformf::eye()};
};
}  // namespace My::MyScene

#include "details/WorldToLocal_AutoRefl.inl"
