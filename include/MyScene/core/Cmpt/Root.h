//
// Created by Admin on 27/02/2025.
//

#pragma once

#include "Component.h"

#include <MyGM/transform.h>

#include <MyDP/Basic/Read.h>

namespace My::Cmpt {
class Transform;
class L2W;
class SObjPtr;

class Root : public Component {
 public:
  static void OnRegist();

  void OnUpdate(const Transform* tsfm, L2W* l2w, const SObjPtr* ptr) const;
};
}  // namespace My::Cmpt
