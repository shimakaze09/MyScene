//
// Created by Admin on 29/12/2024.
//

#include <MyECS/World.h>
#include <MyScene/MyScene.h>

#include <iostream>

using namespace My::MyECS;
using namespace My::MyScene;
using namespace std;

struct PrintSystem {
  static void OnUpdate(Schedule& s) {
    s.Register([](const LocalToWorld* l2w) { cout << l2w->value << endl; },
               "print");
  }
};

int main() {
  RTDCmptTraits::Instance().Register<LocalToWorld, Scale>();

  World w;

  w.systemMngr.Register<PrintSystem, TRSToLocalToWorldSystem>();

  auto [e, l2w, s] = w.entityMngr.Create<LocalToWorld, Scale>();
  s->value = 2.f;
  w.Update();
  cout << w.GenUpdateFrameGraph().Dump() << endl;
}
