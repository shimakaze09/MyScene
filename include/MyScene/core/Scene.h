//
// Created by Admin on 29/12/2024.
//

#pragma once

#include "SObj.h"

#include <MyECS/World.h>

#include <MyDP/Basic/Read.h>

namespace My {
class Scene : public World {
 public:
  Read<Scene, SObj*> root{nullptr};

  Scene(const std::string& name = "");
  virtual ~Scene();

  // auto add Cmpt::Transform
  // if parent == nullptr, it will be added to root
  template <typename... Cmpts>
  std::tuple<SObj*, Cmpt::Transform*, Cmpts*...> CreateSObj(
      const std::string& name, SObj* parent = nullptr);

 private:
  using World::CreateEntity;
};
}  // namespace My

#include "detail/Scene.inl"
