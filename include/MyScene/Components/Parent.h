//
// Created by Admin on 13/03/2025.
//

#pragma once

#include <MyECS/Entity.h>
#include <vector>

namespace My::MyScene {
struct Parent {
  MyECS::Entity value{MyECS::Entity::Invalid()};
};
}  // namespace My::MyScene

#include "details/Parent_AutoRefl.inl"
