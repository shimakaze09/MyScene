//
// Created by Admin on 17/02/2025.
//

#include <MyScene/tool/Accel/detail/PrimitiveGetter.h>

#include <MyScene/core/Primitive/Plane.h>
#include <MyScene/core/Primitive/Sphere.h>
#include <MyScene/core/Primitive/TriMesh.h>
#include <MyScene/core/Primitive/Triangle.h>

using namespace My;

detail::Accel_::PrimitiveGetter::PrimitiveGetter() {
  Regist<Plane, Sphere, TriMesh>();

  Regist([this](Triangle* tri) { rst = tri->mesh; });
}

Primitive* detail::Accel_::PrimitiveGetter::Visit(Primitive* primitive) const {
  RawPtrVisitor<PrimitiveGetter, Primitive>::Visit(primitive);
  return rst;
}