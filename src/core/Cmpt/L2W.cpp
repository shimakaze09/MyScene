//
// Created by Admin on 23/02/2025.
//

#include <MyScene/core/Cmpt/L2W.h>

#include <MyScene/core/Cmpt/SObjPtr.h>
#include <MyScene/core/Cmpt/Transform.h>

#include <MyScene/core/SObj.h>

using namespace My;

void Cmpt::L2W::OnUpdate(const Transform* tsfm, const SObjPtr* ptr) {
  value = tsfm->value;
  for (auto cur = ptr->sobj->parent; cur != nullptr; cur = cur->parent)
    value = cur->Get<Transform>()->value * value;
}

const quatf Cmpt::L2W::WorldRot() const {
  return value->decompose_quatenion();
}

const pointf3 Cmpt::L2W::WorldPos() const {
  return value->decompose_position();
}

const vecf3 Cmpt::L2W::FrontInWorld() const {
  return (value * vecf3{0, 0, 1}).normalize();
}

const vecf3 Cmpt::L2W::RightInWorld() const {
  return (value * vecf3{1, 0, 0}).normalize();
}

const vecf3 Cmpt::L2W::UpInWorld() const {
  return (value * vecf3{0, 1, 0}).normalize();
}
