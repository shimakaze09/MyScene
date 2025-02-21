//
// Created by Admin on 29/12/2024.
//

#include <MyScene/core/Scene.h>

using namespace std;
using namespace My;

Scene::Scene(const std::string& name)
    : root{new SObj(this, get<0>(World::CreateEntity<>()), name)} {}

Scene::~Scene() {
  delete root;
}
