//
// Created by Admin on 28/02/2025.
//

#pragma once

#include "Component.h"

#include <MyGM/scale.h>

namespace My::Cmpt {
class Scale : Component {
 public:
  scalef3 value{1.f};

  static void OnRegist();
};
}  // namespace My::Cmpt
