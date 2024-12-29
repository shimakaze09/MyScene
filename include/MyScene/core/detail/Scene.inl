//
// Created by Admin on 29/12/2024.
//

#pragma once

#include "../Component.h"

namespace My {
template <typename... Cmpts>
std::tuple<SObj*, Cmpts*...> Scene::CreateSObj(const std::string& name,
                                               SObj* parent) {
  static_assert((std::is_base_of_v<Component, Cmpts> && ...));
  assert(!parent || parent->IsDescendantOf(root));

  auto rst = World::CreateEntity<Cmpts...>();
  auto entity = std::get<Entity*>(rst);
  auto sobj = new SObj(entity, name);

 (parent ? parent : root.get())->AddChild(sobj);

  return {sobj, std::get<Cmpts*>(rst)...};
}
}  // namespace My
