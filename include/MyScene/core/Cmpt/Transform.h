//
// Created by Admin on 29/12/2024.
//

#pragma once

#include "Component.h"

#include <MyGM/transform.h>

#include <MyDP/Basic/Read.h>

namespace My::Cmpt {
class Position;
class Rotation;
class Scale;

class Transform : public Component {
 public:
  [[not_serialize]]
  Read<Transform, transformf> value{transformf::eye()};

  static void OnRegister();

  void OnUpdate(const Position* p, const Rotation* r, const Scale* s);
};
}  // namespace My::Cmpt
