//
// Created by Admin on 29/12/2024.
//

#pragma once

#include "SObj.h"

#include <MyECS/core/World.h>

namespace My {
class Scene : public World {
 public:
  Scene(const std::string& name);

  template <typename... Cmpts>
  std::tuple<Cmpt::SObj*, Cmpts*...> CreateSObj(Cmpt::SObj* parent = nullptr);

  Cmpt::SObj* Root() { return root; }

  const Cmpt::SObj* Root() const { return root; }

 private:
  Cmpt::SObj* root;

  using World::CreateEntity;
};
}  // namespace My

#include "detail/Scene.inl"
