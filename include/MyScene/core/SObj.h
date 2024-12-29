//
// Created by Admin on 29/12/2024.
//

#pragma once

#include <MyECS/Entity.h>

#include <MyGM/transform.h>

#include <string>

namespace My {
class Scene;

class SObj {
 public:
  std::string name;

  // children and parent
  SObj* Parent() const noexcept { return parent; }

  std::set<SObj*> Children() const noexcept { return children; }

  void AddChild(SObj* sobj);
  void ReleaseChild(SObj* sobj);

  bool IsDescendantOf(SObj* sobj) const;

  template <typename Cmpt>
  Cmpt* Get();

  template <typename Cmpt>
  const Cmpt* Get() const;

  const std::vector<std::tuple<void*, size_t>> Components() const {
    return entity->Components();
  }

  template <typename... Cmpts>
  std::tuple<Cmpts*...> Attach();

  template <typename Cmpt>
  Cmpt* GetOrAttach();

  template <typename... Cmpts>
  void Detach();

  bool IsAlive() const noexcept { return entity->IsAlive(); }

 private:
  SObj* parent{nullptr};
  std::set<SObj*> children;

 private:
  SObj(Entity* entity, const std::string& name);
  virtual ~SObj();
  Entity* entity;
  friend class Scene;
};
}  // namespace My

#include "detail/SObj.inl"
