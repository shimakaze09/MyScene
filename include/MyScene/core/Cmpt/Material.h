//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "../Component.h"

#include "../Material/Material.h"

#include <MyDP/Basic/Read.h>

namespace My::Cmpt {

class Material : public Component {
 public:
  Read<Material, My::Material*> material{nullptr};

  void SetMaterial(My::Material* material) {
    delete this->material;
    this->material = material;
  }
};
}  // namespace My::Cmpt
