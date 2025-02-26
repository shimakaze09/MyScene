//
// Created by Admin on 30/12/2024.
//

#include <MyScene/tool/SceneReflectionInit.h>

#include <MyScene/core.h>

#include <MyDP/Reflection/Reflection.h>

using namespace My;
using namespace std;

void My::SceneReflectionInit() {
  Scene s("tmp");
  auto [sobj] = s.CreateSObj<>("tmp");

  vtable_of<SObj>::regist(sobj);

  Reflection<SObj>::Instance()
      .SetName("My::SObj")
      .Regist(&SObj::name, "name")
      .Regist(&SObj::children, "children");

  Reflection<Scene>::Instance()
      .SetName("My::Scene")
      .Regist(&Scene::root, "root")
      .RegistConstructor();

  // =================== Component ===================

  Reflection<Cmpt::SObjPtr>::Instance()
      .SetName("My::Cmpt::SObjPtr")
      .RegistConstructor([](SObj* sobj) { return sobj->Get<Cmpt::SObjPtr>(); });

  Reflection<Cmpt::Position>::Instance()
      .SetName("My::Cmpt::Position")
      .Regist(&Cmpt::Position::value, "value")
      .RegistConstructor(
          [](SObj* sobj) { return sobj->Get<Cmpt::Position>(); });

  Reflection<Cmpt::Rotation>::Instance()
      .SetName("My::Cmpt::Rotation")
      .Regist(&Cmpt::Rotation::value, "value")
      .RegistConstructor(
          [](SObj* sobj) { return sobj->Get<Cmpt::Rotation>(); });

  Reflection<Cmpt::Scale>::Instance()
      .SetName("My::Cmpt::Scale")
      .Regist(&Cmpt::Scale::value, "value")
      .RegistConstructor([](SObj* sobj) { return sobj->Get<Cmpt::Scale>(); });

  Reflection<Cmpt::Transform>::Instance()
      .SetName("My::Cmpt::Transform")
      .RegistConstructor(
          [](SObj* sobj) { return sobj->Get<Cmpt::Transform>(); });

  Reflection<Cmpt::L2W>::Instance()
      .SetName("My::Cmpt::L2W")
      .RegistConstructor([](SObj* sobj) { return sobj->Get<Cmpt::L2W>(); });

  Reflection<Cmpt::Camera>::Instance()
      .SetName("My::Cmpt::Camera")
      .Regist(&Cmpt::Camera::ar, "ar")
      .Regist(&Cmpt::Camera::fov, "fov")
      .RegistConstructor([](SObj* sobj) {
        auto [cmpt] = sobj->Attach<Cmpt::Camera>();
        return cmpt;
      });

  Reflection<Cmpt::Geometry>::Instance()
      .SetName("My::Cmpt::Geometry")
      .Regist(&Cmpt::Geometry::primitive, "primitive")
      .RegistConstructor([](SObj* sobj) {
        auto [cmpt] = sobj->Attach<Cmpt::Geometry>();
        return cmpt;
      });

  Reflection<Cmpt::Light>::Instance()
      .SetName("My::Cmpt::Light")
      .Regist(&Cmpt::Light::light, "light")
      .RegistConstructor([](SObj* sobj) {
        auto [cmpt] = sobj->Attach<Cmpt::Light>();
        return cmpt;
      });

  Reflection<Cmpt::Material>::Instance()
      .SetName("My::Cmpt::Material")
      .Regist(&Cmpt::Material::material, "material")
      .RegistConstructor([](SObj* sobj) {
        auto [cmpt] = sobj->Attach<Cmpt::Material>();
        return cmpt;
      });

  // =================== Light ===================

  Reflection<Light>::Instance().SetName("My::Light").RegistConstructor();

  Reflection<AreaLight>::Instance()
      .SetName("My::AreaLight")
      .Regist(&AreaLight::intensity, "intensity")
      .Regist(&AreaLight::color, "color")
      .Regist(&AreaLight::texture, "texture")
      .RegistConstructor();

  Reflection<DirLight>::Instance()
      .SetName("My::DirLight")
      .Regist(&DirLight::intensity, "intensity")
      .Regist(&DirLight::color, "color")
      .RegistConstructor();

  Reflection<EnvLight>::Instance()
      .SetName("My::EnvLight")
      .Regist(&EnvLight::intensity, "intensity")
      .Regist(&EnvLight::color, "color")
      .Regist(&EnvLight::texture, "texture")
      .RegistConstructor();

  Reflection<PointLight>::Instance()
      .SetName("My::PointLight")
      .Regist(&PointLight::intensity, "intensity")
      .Regist(&PointLight::color, "color")
      .RegistConstructor();

  // =================== Primitive ===================

  Reflection<Primitive>::Instance()
      .SetName("My::Primitive")
      .RegistConstructor();

  Reflection<Sphere>::Instance().SetName("My::Sphere").RegistConstructor();

  Reflection<Square>::Instance().SetName("My::Square").RegistConstructor();

  Reflection<Triangle>::Instance()
      .SetName("My::Triangle")
      .Regist(&Triangle::mesh, "mesh")
      .Regist(&Triangle::indices, "indices")
      .RegistConstructor();

  Reflection<TriMesh>::Instance()
      .SetName("My::TriMesh")
      .Regist(&TriMesh::indices, "indices")
      .Regist(&TriMesh::positions, "positions")
      .Regist(&TriMesh::texcoords, "texcoords")
      .Regist(&TriMesh::normals, "normals")
      .Regist(&TriMesh::tangents, "tangents")
      .RegistConstructor();

  // =================== Material ===================

  Reflection<Material>::Instance().SetName("My::Material");

  Reflection<stdBRDF>::Instance()
      .SetName("My::stdBRDF")
      .Regist(&stdBRDF::albedo_factor, "albedo_factor")
      .Regist(&stdBRDF::albedo_texture, "albedo_texture")
      .Regist(&stdBRDF::roughness_factor, "roughness_factor")
      .Regist(&stdBRDF::roughness_texture, "roughness_texture")
      .Regist(&stdBRDF::metalness_factor, "metalness_factor")
      .Regist(&stdBRDF::metalness_texture, "metalness_texture")
      .Regist(&stdBRDF::normal_map, "normal_map")
      .RegistConstructor();

  // =================== Resource ===================

  Reflection<Texture2D>::Instance()
      .SetName("My::Texture2D")
      .Regist(&Texture2D::inv_u, "inv_u")
      .Regist(&Texture2D::inv_v, "inv_v")
      .Regist(&Texture2D::swap_uv, "swap_uv")
      .Regist(&Texture2D::wrap_u, "wrap_u")
      .Regist(&Texture2D::wrap_v, "wrap_v")
      .Regist(&Texture2D::path, "path");
  //   .RegistConstructor([](const string& path) { return new Texture2D{path}; });
}