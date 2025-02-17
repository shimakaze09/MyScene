//
// Created by Admin on 17/02/2025.
//

#pragma once

#include <MyDP/Visitor/MultiVisitor.h>

#include <MyGM/ray.h>

namespace My {
class BVH;
class Primitive;
class Square;
class Sphere;
class Triangle;
class TriMesh;

class IntersectorVisibility
    : public RawPtrMultiVisitor<IntersectorVisibility, Primitive> {
 public:
  IntersectorVisibility();

  bool Visit(const BVH* bvh, const rayf3& r) const;

 protected:
  using RawPtrMultiVisitor<IntersectorVisibility, Primitive>::Visit;
  void ImplVisit(const Square* primitive);
  void ImplVisit(const Sphere* primitive);
  void ImplVisit(const Triangle* primitive);

 private:
  mutable bool isIntersect;
  mutable rayf3 r;
};
}  // namespace My
