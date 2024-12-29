//
// Created by Admin on 29/12/2024.
//

#include <MyScene/core/Cmpt/Transform.h>
#include <MyScene/core/Scene.h>

#include <iostream>

using namespace std;
using namespace My;

int main() {
  Scene scene("scene");

  auto [sobj0, tsfm0] = scene.CreateSObj<Cmpt::Transform>("sobj0");
  auto [sobj1, tsfm1] = scene.CreateSObj<Cmpt::Transform>("sobj1");
  auto [sobj2, tsfm2] = scene.CreateSObj<Cmpt::Transform>("sobj2");

  sobj0->AddChild(sobj1);
  sobj0->AddChild(sobj2);

  tsfm0->Init({0.f, 0.f, 1.f});
  tsfm1->SetScale({2.f});
  tsfm2->SetRotation({vecf3{0.f, 1.f, 0.f}, to_radian(-90.f)});

  tsfm0->GetLocalToWorldMatrix().print();
  tsfm1->GetLocalToWorldMatrix().print();
  tsfm2->GetLocalToWorldMatrix().print();

  return 0;
}