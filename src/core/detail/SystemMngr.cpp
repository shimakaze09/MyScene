//
// Created by Admin on 21/02/2025.
//

#include <MyScene/core/detail/SystemMngr.h>

using namespace My;

void SystemMngr::Update(World* world) {
  for (const auto& [ID, onUpdate] : OnUpdates)
    onUpdate(world);
}
