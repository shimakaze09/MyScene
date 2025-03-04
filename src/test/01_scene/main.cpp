//
// Created by Admin on 30/12/2024.
//

#include <MyScene/core/Scene.h>

#include <MyScene/core/Cmpt/Camera.h>
#include <MyScene/core/Cmpt/Geometry.h>
#include <MyScene/core/Cmpt/Light.h>
#include <MyScene/core/Cmpt/Material.h>
#include <MyScene/core/Cmpt/Transform.h>

#include <MyScene/core/Light/PointLight.h>
#include <MyScene/core/Material/stdBRDF.h>
#include <MyScene/core/Primitive/Sphere.h>

#include <iostream>

using namespace std;
using namespace My;

int main() {
  Scene::OnRegister();

  Scene scene("scene");

  auto [sobj0, camera] = scene.CreateSObj<Cmpt::Camera>("sobj0");
  auto [sobj1, geo, mat] =
      scene.CreateSObj<Cmpt::Geometry, Cmpt::Material>("sobj1");
  auto [sobj2, light] = scene.CreateSObj<Cmpt::Light>("sobj2");

  geo->SetPrimitive(new Sphere);
  mat->SetMaterial(new stdBRDF);
  light->SetLight(new PointLight{1.f, 1.f});

  return 0;
}
