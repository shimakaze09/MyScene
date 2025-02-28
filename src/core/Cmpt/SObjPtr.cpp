//
// Created by Admin on 28/02/2025.
//

#include <MyScene/core/Cmpt/SObjPtr.h>

#include <MyScene/core/SObj.h>

#include "detail/dynamic_reflection/SObjPtr.inl"

using namespace My;
using namespace std;

void Cmpt::SObjPtr::OnRegist() {
  detail::dynamic_reflection::ReflRegist_SObjPtr();
}
