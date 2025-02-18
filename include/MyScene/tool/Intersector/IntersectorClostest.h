//
// Created by Admin on 18/02/2025.
//

#pragma once

#include <MyDP/Visitor/Visitor.h>

#include <MyGM/MyGM>

namespace My {
class BVH;
class SObj;
class Primitive;
class Square;
class Sphere;
class Triangle;
class TriMesh;

class IntersectorClostest
    : public RawPtrVisitor<IntersectorClostest, Primitive> {
 public:
  IntersectorClostest();

  struct Rst {
    bool IsIntersected() const noexcept { return sobj != nullptr; }

    const SObj* sobj{nullptr};
    float t;
    pointf2 uv;
    normalf norm;
    vecf3 tangent;
  };

  const Rst Visit(const BVH* bvh, const rayf3& r) const;

 protected:
  using RawPtrVisitor<IntersectorClostest, Primitive>::Visit;
  void ImplVisit(const Square* primitive);
  void ImplVisit(const Sphere* primitive);
  void ImplVisit(const Triangle* primitive);

 private:
  mutable rayf3 r;
  mutable Rst rst;
  mutable const Primitive* primitive;
  mutable std::array<float, 3> wuv;
};
}  // namespace My
