//
// Created by Admin on 23/02/2025.
//

#include <MyScene/core/Cmpt/L2W.h>

#include "detail/dynamic_reflection/L2W.inl"

#include <MyScene/core/Cmpt/SObjPtr.h>
#include <MyScene/core/Cmpt/Transform.h>

#include <MyScene/core/SObj.h>

using namespace My;

void Cmpt::L2W::OnRegist() {
  detail::dynamic_reflection::ReflRegist_L2W();
}

const pointf3 Cmpt::L2W::WorldPos() const noexcept {
  return value->decompose_position();
}

const quatf Cmpt::L2W::WorldRot() const noexcept {
  return value->decompose_quatenion();
}

const scalef3 Cmpt::L2W::WorldScale() const noexcept {
  return value->decompose_scale();
}

const vecf3 Cmpt::L2W::FrontInWorld() const noexcept {
  return (value * vecf3{0, 0, 1}).normalize();
}

const vecf3 Cmpt::L2W::RightInWorld() const noexcept {
  return (value * vecf3{1, 0, 0}).normalize();
}

const vecf3 Cmpt::L2W::UpInWorld() const noexcept {
  return (value * vecf3{0, 1, 0}).normalize();
}
