//
// Created by Admin on 17/02/2025.
//

#pragma once

#include "Primitive.h"

#include <MyGM/normal.h>
#include <MyGM/point.h>

namespace My {
// center : (0, 0, 0)
// side length : 2
// normal: (0, 1, 0)
class Square : public Primitive {
  static constexpr pointf3 center{0, 0, 0};
  static constexpr normalf normal{0, 1, 0};
  static constexpr float side_length{2.f};
};
}  // namespace My
