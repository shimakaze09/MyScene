//
// Created by Admin on 21/02/2025.
//

#pragma once

#include <MyECS/World.h>

namespace My {
class SystemMngr {
 public:
  static SystemMngr& Instance() noexcept {
    static SystemMngr instance;
    return instance;
  }

 private:
  friend class SObj;
  friend class Scene;

  template <typename Cmpt>
  void Regist();

  void Update(World* world);

  std::map<size_t, std::function<void(World*)>> OnUpdates;
};
}  // namespace My

#include "SystemMngr.inl"
