//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "../Component.h"

#include "../Primitive/Primitive.h"

#include <MyDP/Basic/Read.h>

namespace My::Cmpt {

class Geometry : public Component {
 public:
  Read<Geometry, Primitive*> primitive{nullptr};

  void SetPrimitive(Primitive* primitive) {
    delete this->primitive;
    this->primitive = primitive;
  }

  Geometry() = default;

  virtual ~Geometry() { delete primitive; }

  Geometry(Geometry&& geo) noexcept : Component(geo) {
    primitive = geo.primitive;
    geo.primitive = nullptr;
  }
};
}  // namespace My::Cmpt
