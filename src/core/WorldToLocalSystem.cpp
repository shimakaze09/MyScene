//
// Created by Admin on 13/03/2025.
//

#include <MyScene/Systems/WorldToLocalSystem.h>

#include <MyScene/Components/LocalToWorld.h>
#include <MyScene/Components/WorldToLocal.h>

using namespace My::MyScene;

void WorldToLocalSystem::OnUpdate(MyECS::Schedule& schedule) {
  schedule.Register(
      [](WorldToLocal* w2l, const LocalToWorld* l2w) {
        w2l->value = l2w->value.inverse();
      },
      "TRSToWorldToLocalSystem");
}
