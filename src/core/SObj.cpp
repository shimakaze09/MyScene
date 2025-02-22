//
// Created by Admin on 29/12/2024.
//

#include <MyScene/core/SObj.h>

#include <MyScene/core/Cmpt/Transform.h>

using namespace My;
using namespace std;

SObj::SObj(Scene* scene, Entity* entity, const string& name)
    : scene{scene}, entity(entity), name(name) {}

SObj::~SObj() {
  if (entity && entity->IsAlive())
    entity->Release();
  for (const auto& child : children.get())
    delete child;
}

void SObj::AddChild(SObj* sobj) {
  assert(sobj != this);
  assert(scene == sobj->scene);

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

bool SObj::IsDescendantOf(SObj* sobj) const {
  assert(scene == sobj->scene);

  if (sobj == this)
    return true;

  if (parent == nullptr)
    return false;

  return parent->IsDescendantOf(sobj);
}

const vector<tuple<void*, size_t>> SObj::Components() const {
  return entity->Components();
}

bool SObj::IsAlive() const noexcept {
  return entity->IsAlive();
}

// Attach, Detach, Release, World::CreateEntity
void SObj::AddCommand(const std::function<void()>& command) {
  entity->AddCommand(command);
}
