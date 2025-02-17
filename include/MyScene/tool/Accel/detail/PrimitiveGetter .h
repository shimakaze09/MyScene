//
// Created by Admin on 17/02/2025.
//

#pragma once

#include <MyDP/Basic/Read.h>
#include <MyDP/Visitor/Visitor.h>

namespace My {
class Primitive;
}

namespace My::detail::Accel_ {
class PrimitiveGetter : public RawPtrVisitor<PrimitiveGetter, Primitive> {
 public:
  PrimitiveGetter();
  const Primitive* Visit(const Primitive* primitive) const;

 private:
  mutable const Primitive* rst;

 protected:
  template <typename T>
  void ImplVisit(const T* primitive) {
    rst = primitive;
  }
};
}  // namespace My::detail::Accel_
