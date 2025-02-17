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
};
}  // namespace My
