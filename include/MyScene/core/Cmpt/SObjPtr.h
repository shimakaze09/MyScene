//
// Created by Admin on 23/02/2025.
//

#pragma once

#include "Component.h"

#include <MyDP/Basic/Read.h>

namespace My {
class Scene;
class SObj;
}  // namespace My

namespace My::Cmpt {
class SObjPtr : Component {
 public:
  [[not_serialize]]
  Read<Scene, SObj*> value{nullptr};

  static void OnRegist();
};
}  // namespace My::Cmpt
