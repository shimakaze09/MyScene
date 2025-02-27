//
// Created by Admin on 30/12/2024.
//

#pragma once

#include <string>

namespace My {
class SObj;
class Scene;

class IDeserializer {
 public:
  virtual Scene* DeserializeScene(const std::string& path) = 0;
  virtual SObj* DeserializeSObj(const std::string& path) = 0;
};
}  // namespace My