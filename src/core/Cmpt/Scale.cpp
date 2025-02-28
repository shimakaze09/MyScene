//
// Created by Admin on 28/02/2025.
//

#include <MyScene/core/Cmpt/Scale.h>

#include <MyScene/core/SObj.h>

#include "detail/dynamic_reflection/Scale.inl"

using namespace My;
using namespace std;

void Cmpt::Scale::OnRegist() {
  detail::dynamic_reflection::ReflRegist_Scale();
}
