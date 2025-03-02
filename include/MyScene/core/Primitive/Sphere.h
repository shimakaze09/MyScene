//
// Created by Admin on 30/12/2024.
//

#pragma once

#include <MyGM/point.h>
#include "Primitive.h"

namespace My {
// center : (0, 0, 0)
// radius : 1
class Sphere : public Primitive {
 public:
  static constexpr pointf3 center{0, 0, 0};
  static constexpr float radius{1.f};

  static void OnRegister();
};
}  // namespace My