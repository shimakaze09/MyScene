//
// Created by Admin on 29/12/2024.
//

#include <MyScene/core/SObj.h>

#include <MyScene/core/Transform.h>

using namespace My;

const transformf Cmpt::SObj::GetLocalToWorldMatrix() const {
  auto tsfm = transformf::eye();
  for (auto cur = this; cur != nullptr; cur = cur->Parent()) {
    auto cmpt = cur->GetEntity()->Get<Cmpt::Transform>();
    if (cmpt)
      tsfm = cmpt->tsfm.Get() * tsfm;
  }
  return tsfm;
}