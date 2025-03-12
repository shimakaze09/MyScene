//
// Created by Admin on 13/03/2025.
//

#pragma once

#include <MyECS/World.h>

namespace My {
namespace MyScene {
struct TRSToLocalToWorldSystem {
  static void OnUpdate(UECS::Schedule& schedule);
};
}  // namespace MyScene
}  // namespace My
