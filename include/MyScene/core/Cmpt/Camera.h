//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "Component.h"

#include <MyGM/ray.h>
#include <MyGM/transform.h>

#include <MyDP/Basic/Read.h>

namespace My::Cmpt {
// front is -z in local coordinate
class [[info("pinhole camera")]] Camera : public Component {
 public:
  [[info("width / height")]] [[pretty_name("aspect ratio")]]
  float ar{16.f / 9.f};

  [[info("in verticle, in radian")]] [[pretty_name("field of view")]]
  float fov{My::to_radian(60.f)};

  static void OnRegister();

  struct CoordinateSystem {
    pointf3 pos;
    vecf3 posToLBCorner;  // from camera position to left-bottom corner
    vecf3 right;          // right.norm() == width
    vecf3 up;             // up.norm() == height
  };

  const CoordinateSystem GenCoordinateSystem(
      const transformf& l2w) const noexcept;

  rayf3 GenRay(float u, float v, const CoordinateSystem& s) const noexcept {
    return {s.pos, (s.posToLBCorner + u * s.right + v * s.up).normalize()};
  }
};
}  // namespace My::Cmpt
