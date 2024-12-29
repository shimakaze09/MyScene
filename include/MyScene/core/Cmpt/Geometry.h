//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "../Component.h"

namespace My {
class Primitive;
}

namespace My::Cmpt {

class Geometry : public Component {
 public:
  Primitive* const volatile primitive{nullptr};

  void SetPrimitive(Primitive* primitive) {
    delete this->primitive;
    const_cast<Primitive*&>(this->primitive) = primitive;
  }
};
}  // namespace My::Cmpt
