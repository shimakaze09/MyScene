//
// Created by Admin on 29/12/2024.
//

#pragma once

#include "Cmpt/Transform.h"

#include <MyECS/Entity.h>

#include <MyGM/transform.h>

#include <MyDP/Basic/Read.h>

#include <string>

namespace My {
class Scene;

class SObj {
 public:
  std::string name;

  Read<SObj, SObj*> parent{nullptr};
  Read<SObj, std::set<SObj*>> children;

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

  // not run in Scene.Each
  template <typename Cmpt>
  Cmpt* GetOrAttach();

  template <typename... Cmpts>
  void Detach();

  bool IsAlive() const noexcept { return entity->IsAlive(); }

 protected:
  SObj() : entity{nullptr} {}

  SObj(Scene* scene, Entity* entity, const std::string& name);
  virtual ~SObj();
  Entity* entity;
  Scene* scene;
  friend class Scene;
};
}  // namespace My

#include "detail/SObj.inl"
