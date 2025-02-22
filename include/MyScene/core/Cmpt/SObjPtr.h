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
struct SObjPtr : Component {
  Read<Scene, SObj*> sobj{nullptr};
};
}  // namespace My::Cmpt
