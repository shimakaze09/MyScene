//
// Created by Admin on 22/02/2025.
//

#pragma once

#include "Component.h"

#include <MyGM/transform.h>

#include <MyDP/Basic/Read.h>

namespace My::Cmpt {
class Root;

// local to world transformation
class L2W : public Component {
 public:
  [[is_not_serialize]]
  Read<Root, transformf> value{transformf::eye()};

  static void OnRegist();

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
