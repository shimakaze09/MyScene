//
// Created by Admin on 13/03/2025.
//

#include <MyScene/Systems/TRSToLocalToWorldSystem.h>

#include <MyScene/Components/LocalToWorld.h>
#include <MyScene/Components/Scale.h>

using namespace My::MyScene;

void TRSToLocalToWorldSystem::OnUpdate(UECS::Schedule& schedule) {
  schedule.Register(
      [](LocalToWorld* l2w, const Scale* s) {
        l2w->value = transformf{scalef3{s->value}};
      },
      "TRSToLocalToWorldSystem::S");
}
