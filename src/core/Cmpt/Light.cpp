//
// Created by Admin on 28/02/2025.
//

#include <MyScene/core/Cmpt/Light.h>

#include <MyScene/core/SObj.h>

#include "detail/dynamic_reflection/Light.inl"

using namespace My;
using namespace std;

void Cmpt::Light::OnRegist() {
  detail::dynamic_reflection::ReflRegist_Light();
}

Cmpt::Light::Light() = default;

Cmpt::Light::~Light() {
  delete light;
}

Cmpt::Light::Light(Light&& light) noexcept : light{light.light} {
  light.light.val = nullptr;
}

void Cmpt::Light::SetLight(My::Light* light) {
  delete this->light;
  this->light.val = light;
}
