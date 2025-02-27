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

  const pointf3 WorldPos() const noexcept;
  const quatf WorldRot() const noexcept;
  const scalef3 WorldScale() const noexcept;

  // normalized
  const vecf3 FrontInWorld() const noexcept;
  // normalized
  const vecf3 RightInWorld() const noexcept;
  // normalized
  const vecf3 UpInWorld() const noexcept;
};
}  // namespace My::Cmpt
