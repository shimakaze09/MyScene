//
// Created by Admin on 23/02/2025.
//

#pragma once

#include "Component.h"

#include <MyGM/point.h>

namespace My::Cmpt {
class Position : Component {
 public:
  pointf3 value{0.f};

  static void OnRegister();
};
}  // namespace My::Cmpt
