//
// Created by Admin on 29/12/2024.
//

#include <MyScene/core/Scene.h>

#include <iostream>

using namespace std;
using namespace My;

class Mover : public Component {
 public:
  void OnUpdate(Cmpt::Position* p) const { p->value += vecf3{1, 1, 1}; }
};

int main() {
  Scene::OnRegist();

  Scene scene("scene");

  auto [sobj0, mover] = scene.CreateSObj<Mover>("sobj0");
  auto [sobj1] = scene.CreateSObj<>("sobj1");
  auto [sobj2] = scene.CreateSObj<>("sobj2");

  sobj0->AddChild(sobj1);
  sobj0->AddChild(sobj2);

  cout << sobj0->Get<Cmpt::Position>()->value << endl;
  scene.Update();
  cout << sobj0->Get<Cmpt::Position>()->value << endl;

  return 0;
}
