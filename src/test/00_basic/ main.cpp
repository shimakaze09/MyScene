//
// Created by Admin on 29/12/2024.
//

#include <MyECS/World.h>
#include <MyScene/MyScene.h>

#include <iostream>

using namespace My::MyECS;
using namespace My::MyScene;
using namespace My;
using namespace std;

class PrintSystem : public System {
 public:
  using System::System;

  virtual void OnUpdate(Schedule& schedule) override {
    schedule.Register(
        [](const WorldToLocal* w2l, const LocalToWorld* l2w) {
          l2w->value.print();
          w2l->value.print();
        },
        "print");
  }
};

int main() {
  RTDCmptTraits::Instance()
      .Register<
          //LocalToParent,
          LocalToWorld,
          //NonUniformScale,
          //Parent,
          Rotation,
          //RotationEuler,
          Scale, Translation, WorldToLocal>();

  World w;

  w.systemMngr
      .Register<PrintSystem, TRSToLocalToWorldSystem, WorldToLocalSystem>();

  auto [e, w2l, l2w, t, r, s] =
      w.entityMngr
          .Create<WorldToLocal, LocalToWorld, Translation, Rotation, Scale>();
  t->value = {1, 0, 1};
  r->value = {vecf3{0, 1, 0}, to_radian(45.f)};
  s->value = 2.f;

  w.Update();

  cout << w.GenUpdateFrameGraph().Dump() << endl;
}
