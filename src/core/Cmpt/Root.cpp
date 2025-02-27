//
// Created by Admin on 27/02/2025.
//

#include <MyScene/core/Cmpt/Root.h>

#include <MyScene/core/Cmpt/L2W.h>
#include <MyScene/core/Cmpt/SObjPtr.h>
#include <MyScene/core/Cmpt/Transform.h>

#include <MyScene/core/SObj.h>

using namespace My;
using namespace std;

void Cmpt::Root::OnUpdate(const Transform* tsfm, L2W* l2w,
                          const SObjPtr* ptr) const {
  stack<SObj*> sobjStack;
  l2w->value = tsfm->value;
  for (auto child : ptr->sobj->children)
    sobjStack.push(child);
  while (!sobjStack.empty()) {
    auto sobj = sobjStack.top();
    sobjStack.pop();
    sobj->Get<L2W>()->value =
        sobj->parent->Get<L2W>()->value * sobj->Get<Transform>()->value;
    for (auto child : sobj->children)
      sobjStack.push(child);
  }
}