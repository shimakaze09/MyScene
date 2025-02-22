//
// Created by Admin on 17/02/2025.
//

#pragma once

#include "Component.h"

#include <MyGM/transform.h>

#include <MyDP/Basic/Read.h>

namespace My::Cmpt {
struct Position;
struct Rotation;
struct Scale;

class Transform : public Component {
 public:
  Read<Transform, transformf> value{transformf::eye()};

  void OnUpdate(const Position* p, const Rotation* r, const Scale* s);
};
}  // namespace My::Cmpt
