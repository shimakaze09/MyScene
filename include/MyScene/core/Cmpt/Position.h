//
// Created by Admin on 23/02/2025.
//

#pragma once

#include "Component.h"

#include <MyGM/point.h>

namespace My::Cmpt {
struct Position : Component {
  pointf3 value{0.f};
};
}  // namespace My::Cmpt
