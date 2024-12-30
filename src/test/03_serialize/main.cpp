//
// Created by Admin on 30/12/2024.
//

#include <MyScene/tool/SceneReflectionInit.h>
#include <MyScene/tool/serialize/SerializerJSON.h>
#include <MyScene/core/core>

#include <fstream>
#include <iostream>

using namespace std;
using namespace My;

int main() {
  SceneReflectionInit();

  Scene scene("scene");

  auto [sobj0, tsfm0, camera] =
      scene.CreateSObj<Cmpt::Transform, Cmpt::Camera>("sobj0");
  auto [sobj1, tsfm1, geo, mat] =
      scene.CreateSObj<Cmpt::Transform, Cmpt::Geometry, Cmpt::Material>(
          "sobj1");
  auto [sobj2, tsfm2, light] =
      scene.CreateSObj<Cmpt::Transform, Cmpt::Light>("sobj2");

  sobj1->Get<Cmpt::Geometry>()->SetPrimitive(new Sphere);
  auto brdf = new stdBRDF;
  sobj1->Get<Cmpt::Material>()->SetMaterial(brdf);
  sobj2->Get<Cmpt::Light>()->SetLight(new PointLight{1.f, 1.f});

  string path = "../data/tex_square.png";
  brdf->albedo_texture =
      ResourceMngr<Image>::Instance().GetOrCreate(path, path);

  ISerializer* serializer = new SerializerJSON;

  auto rst = serializer->Serialize(&scene);

  ofstream ofs;
  string filename = "../data/test_03_output.myscene";
  ofs.open(filename);
  if (!ofs.is_open()) {
    cerr << "ERROR::main:" << endl
         << "\t" << "open file (" << filename << ") fail" << endl;
    return 1;
  }
  ofs << rst;
  ofs.close();

  cout << rst << endl;
  cout << "--------------------------" << endl;
  cout << "test online: https://www.json.cn/" << endl;
  cout << "save to " << filename << endl;
  return 0;
}
