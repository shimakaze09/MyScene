//
// Created by Admin on 17/02/2025.
//

#pragma once

#include <MyDP/Visitor.h>

#include <MyGM/ray.h>

namespace My {
class BVH;

class IntersectorVisibility {
 public:
  static IntersectorVisibility& Instance() noexcept {
    static IntersectorVisibility instance;
    return instance;
  }

  bool Visit(const BVH* bvh, rayf3 r) const;

 private:
  IntersectorVisibility();
  Visitor<bool(const rayf3& r)> visitor;
};
}  // namespace My
