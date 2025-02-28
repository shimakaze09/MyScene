//
// Created by Admin on 23/02/2025.
//

#pragma once

#include "Component.h"

#include <MyGM/quat.h>

namespace My::Cmpt {
class Rotation : Component {
 public:
  quatf value{quatf::identity()};

  static void OnRegist();
};
}  // namespace My::Cmpt
