//
// Created by Admin on 30/12/2024.
//

#include <MyScene/core/Resource/ResourceMngr.h>
#include <MyScene/tool/SceneReflectionInit.h>
#include <MyScene/tool/serialize/DeserializerJSON.h>
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
  auto [sobj1, tsfm1, geo0, mat] =
      scene.CreateSObj<Cmpt::Transform, Cmpt::Geometry, Cmpt::Material>(
          "sobj1");
  auto [sobj2, tsfm2, geo1, light] =
      scene.CreateSObj<Cmpt::Transform, Cmpt::Geometry, Cmpt::Light>("sobj2");

  geo0->SetPrimitive(new Sphere);
  auto brdf = new stdBRDF;
  mat->SetMaterial(brdf);
  light->SetLight(new PointLight{1.f, 1.f});
  geo1->SetPrimitive(new TriMesh(TriMesh::Type::Cube));

  string path = "../data/tex_square.png";
  brdf->albedo_texture =
      ResourceMngr<Image>::Instance().GetOrCreate(path, path);

  ISerializer* serializer = new SerializerJSON;
  IDeserializer* deserializer = new DeserializerJSON;

  auto rst = serializer->Serialize(&scene);
  auto rstScene = deserializer->DeserializeScene(rst);
  rst = serializer->Serialize(rstScene);

  ofstream ofs;
  string filename = "../data/test_04_output.myscene";
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