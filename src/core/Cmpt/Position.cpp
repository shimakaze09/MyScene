//
// Created by Admin on 28/02/2025.
//

#include <MyScene/core/Cmpt/Position.h>

#include <MyScene/core/SObj.h>

#include "detail/dynamic_reflection/Position.inl"

using namespace My;
using namespace std;

void Cmpt::Position::OnRegist() {
  detail::dynamic_reflection::ReflRegist_Position();
}