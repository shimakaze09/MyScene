//
// Created by Admin on 22/02/2025.
//

#pragma once

#include "Component.h"

#include <MyGM/transform.h>

#include <MyDP/Basic/Read.h>

namespace My::Cmpt {
class Transform;
struct SObjPtr;

class L2W : public Component {
 public:
  Read<L2W, transformf> value;

  void OnUpdate(const Transform* tsfm, const SObjPtr* ptr);

  const pointf3 WorldPos() const;
  const quatf WorldRot() const;
  const vecf3 FrontInWorld() const;
  const vecf3 RightInWorld() const;
  const vecf3 UpInWorld() const;
};
}  // namespace My::Cmpt
