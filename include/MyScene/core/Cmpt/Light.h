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

  Light();
  virtual ~Light();

  Light(Light&& light) noexcept;

  void SetLight(My::Light* light);

  static void OnRegist();
};
}  // namespace My::Cmpt
