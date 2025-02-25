//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "Component.h"

#include "../Light/Light.h"

#include <MyDP/Basic/Read.h>

namespace My::Cmpt {
class Light : public Component {
 public:
  Read<Light, My::Light*> light{nullptr};

  void SetLight(My::Light* light) {
    delete this->light;
    this->light = light;
  }

  Light() = default;

  virtual ~Light() { delete light; }

  Light(Light&& light) noexcept : light{light.light} { light.light = nullptr; }
};
}  // namespace My::Cmpt
