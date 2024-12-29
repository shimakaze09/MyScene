//
// Created by Admin on 29/12/2024.
//

#include <MyScene/core/SObj.h>

#include <MyScene/core/Cmpt/Transform.h>

using namespace My;
using namespace std;

SObj::SObj(Entity* entity, const string& name) : entity(entity), name(name) {}

SObj::~SObj() {
  entity->Release();
  for (const auto& child : children.get())
    delete child;
}

void SObj::AddChild(SObj* sobj) {
  assert(sobj != this);
  if (sobj->parent)
    sobj->parent->children->erase(sobj);

  sobj->parent = this;
  children->insert(sobj);
}

void SObj::ReleaseChild(SObj* sobj) {
  assert(sobj->parent == this);
  children->erase(sobj);
  delete sobj;
}

bool SObj::IsDescendantOf(SObj* impl) const {
  if (impl == this)
    return true;

  if (parent == nullptr)
    return false;

  return parent->IsDescendantOf(impl);
}