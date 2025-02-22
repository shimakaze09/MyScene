//
// Created by Admin on 29/12/2024.
//

#include <MyScene/core/Cmpt/Transform.h>

#include <MyScene/core/Cmpt/Position.h>
#include <MyScene/core/Cmpt/Rotation.h>
#include <MyScene/core/Cmpt/Scale.h>

using namespace My;

void Cmpt::Transform::OnUpdate(const Position* p, const Rotation* r,
                               const Scale* s) {
  value = transformf(p->value, s->value, r->value);
}
