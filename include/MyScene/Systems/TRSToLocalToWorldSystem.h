//
// Created by Admin on 13/03/2025.
//

#pragma once

#include <MyECS/World.h>

namespace My {
namespace MyScene {
class TRSToLocalToWorldSystem : public MyECS::System {
 public:
  using System::System;

  virtual void OnUpdate(MyECS::Schedule& schedule) override;
};
}  // namespace MyScene
}  // namespace My
