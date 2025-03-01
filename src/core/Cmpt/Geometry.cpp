//
// Created by Admin on 28/02/2025.
//

#include <MyScene/core/Cmpt/Geometry.h>

#include <MyScene/core/SObj.h>

#include "detail/dynamic_reflection/Geometry.inl"

using namespace My;
using namespace std;

void Cmpt::Geometry::OnRegist() {
  detail::dynamic_reflection::ReflRegist_Geometry();
}

Cmpt::Geometry::Geometry() = default;

Cmpt::Geometry::~Geometry() {
  delete primitive;
}

Cmpt::Geometry::Geometry(Geometry&& geo) noexcept : primitive{geo.primitive} {
  geo.primitive = nullptr;
}

void Cmpt::Geometry::SetPrimitive(Primitive* primitive) {
  delete this->primitive;
  this->primitive = primitive;
}
