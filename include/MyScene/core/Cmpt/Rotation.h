//
// Created by Admin on 23/02/2025.
//

#pragma once

#include "Component.h"

#include <MyGM/quat.h>

namespace My::Cmpt {
struct Rotation : Component {
  quatf value{quatf::identity()};
};
}  // namespace My::Cmpt
