//
// Created by Admin on 29/12/2024.
//

#pragma once

#include "../ReflAttrs.h"

#include <MyECS/CmptTag.h>

namespace My {
// vtable is typeid
// alignas for __m128
class alignas(16) Component {
 protected:
  virtual ~Component() = default;
};
}  // namespace My
