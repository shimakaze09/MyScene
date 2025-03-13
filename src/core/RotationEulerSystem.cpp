//
// Created by Admin on 13/03/2025.
//

#include <MyScene/Systems/RotationEulerSystem.h>
 
 #include <MyScene/Components/Rotation.h>
 #include <MyScene/Components/RotationEuler.h>
 
 using namespace My::MyScene;
 
void RotationEulerSystem::OnUpdate(MyECS::Schedule& schedule) {
  schedule.Register([](Rotation* rot, const RotationEuler* rot_euler) {
          rot->value = rot_euler->value.to_quat();
      }, SystemFuncName);
}
