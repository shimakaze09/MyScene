//
// Created by Admin on 17/02/2025.
//

#include <MyScene/tool/Accel/detail/PrimitiveGetter.h>

#include <MyScene/core/Primitive/Sphere.h>
#include <MyScene/core/Primitive/TriMesh.h>
#include <MyScene/core/Primitive/Triangle.h>
#include <UScene/core/Primitive/Square.h>

using namespace My;

detail::Accel_::PrimitiveGetter::PrimitiveGetter() {
  RegistC<Square, Sphere, TriMesh>();

  Regist([this](const Triangle* tri) { rst = tri->mesh; });
}

const Primitive* detail::Accel_::PrimitiveGetter::Visit(
    const Primitive* primitive) const {
  RawPtrVisitor<PrimitiveGetter, Primitive>::Visit(primitive);
  return rst;
}