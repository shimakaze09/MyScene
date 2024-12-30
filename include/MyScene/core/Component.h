//
// Created by Admin on 29/12/2024.
//

#pragma once

#include <MyDP/Basic/Read.h>

namespace My {
class SObj;

class Component {
 public:
  Read<SObj, SObj*> sobj{nullptr};

 protected:
  Component() = default;
  virtual ~Component() = default;

};
}  // namespace My
