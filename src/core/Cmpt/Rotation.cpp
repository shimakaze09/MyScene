//
// Created by Admin on 28/02/2025.
//

#include <MyScene/core/Cmpt/Rotation.h>

#include <MyScene/core/SObj.h>

#include "detail/dynamic_reflection/Rotation.inl"

using namespace My;
using namespace std;

void Cmpt::Rotation::OnRegist() {
  detail::dynamic_reflection::ReflRegist_Rotation();
}
