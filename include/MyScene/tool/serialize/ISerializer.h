//
// Created by Admin on 30/12/2024.
//

#pragma once

#include <MyDP/Reflection/ReflTraits.h>

#include <string>

namespace My {
class Scene;
class SObj;

class ISerializer : public ReflTraitsVisitor {
 public:
  virtual std::string Serialize(const Scene* scene) = 0;
  virtual std::string Serialize(const SObj* sobj) = 0;
};
}  // namespace My