//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "../Component.h"

#include "../Material/Material.h"

namespace My::Cmpt {

class Material : public Component {
 public:
  My::Material* const volatile material{nullptr};

  void SetMaterial(My::Material* material) {
    delete this->material;
    const_cast<My::Material*&>(this->material) = material;
  }
};
}  // namespace My::Cmpt
