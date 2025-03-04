//
// Created by Admin on 28/02/2025.
//

#include <MyScene/core/Cmpt/Material.h>

#include <MyScene/core/SObj.h>

#include "detail/dynamic_reflection/Material.inl"

using namespace My;
using namespace std;

void Cmpt::Material::OnRegister() {
  detail::dynamic_reflection::ReflRegister_Material();
}

Cmpt::Material::Material() = default;

Cmpt::Material::~Material() {
  delete material;
}

Cmpt::Material::Material(Material&& material) noexcept
    : material{material.material} {
  material.material = nullptr;
}

void Cmpt::Material::SetMaterial(My::Material* material) {
  delete this->material;
  this->material = material;
}
