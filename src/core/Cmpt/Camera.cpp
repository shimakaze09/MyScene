//
// Created by Admin on 30/12/2024.
//

#include <MyScene/core/Cmpt/Camera.h>
#include <MyScene/core/SObj.h>

#include "detail/dynamic_reflection/Camera.inl"

using namespace My;
using namespace std;

const Cmpt::Camera::CoordinateSystem Cmpt::Camera::GenCoordinateSystem(
    const transformf& l2w) const noexcept {
  CoordinateSystem rst;

  rst.pos = l2w.decompose_position();

  auto rotMatrix = l2w.decompose_rotation_matrix();
  auto front = (rotMatrix * vecf3{0.f, 0.f, -1.f}).normalize();
  auto nRight = front.cross(vecf3{0, 1, 0});
  auto nUp = nRight.cross(front);

  float height = 2 * std::tanf(fov / 2.f);
  float width = height * ar;

  rst.posToLBCorner = front - (width / 2.f) * nRight - (height / 2.f) * nUp;
  rst.right = width * nRight;
  rst.up = height * nUp;

  return rst;
}

void Cmpt::Camera::OnRegist() {
  detail::dynamic_reflection::ReflRegist_Camera();
}
