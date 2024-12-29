//
// Created by Admin on 29/12/2024.
//

#include <MyScene/core/Scene.h>

using namespace std;
using namespace My;

Scene::Scene(const std::string& name)
    : root(get<1>(World::CreateEntity<Cmpt::SObj>())) {
  root->name = name;
}