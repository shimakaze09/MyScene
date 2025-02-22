//
// Created by Admin on 29/12/2024.
//

#include <MyScene/core/Scene.h>

using namespace std;
using namespace My;

Scene::Scene(const std::string& name)
    : root{new SObj(
          this,
          get<Entity*>(
              World::CreateEntity<Cmpt::SObjPtr, Cmpt::Position, Cmpt::Rotation,
                                  Cmpt::Scale, Cmpt::Transform, Cmpt::L2W>()),
          name)} {
  root->Get<Cmpt::SObjPtr>()->sobj.val = root;
}

Scene::~Scene() {
  delete root;
}
