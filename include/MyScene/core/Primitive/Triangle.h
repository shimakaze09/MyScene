//
// Created by Admin on 17/02/2025.
//

#pragma once

#include "Primitive.h"

#include <MyGM/val.h>

namespace My {
class TriMesh;

class Triangle : public Primitive {
 public:
  TriMesh* mesh{nullptr};
  valu3 indices;

  Triangle() = default;

  Triangle(TriMesh* mesh, const valu3& indices)
      : mesh{mesh}, indices{indices} {}

  const pointf2 lerpUV(float w, float u, float v) const;
  const pointf3 lerpPosition(float w, float u, float v) const;
  const normalf lerpNormal(float w, float u, float v) const;
  const vecf3 lerpTangent(float w, float u, float v) const;

  static void OnRegist();
};
}  // namespace My
