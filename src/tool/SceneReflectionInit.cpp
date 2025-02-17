//
// Created by Admin on 30/12/2024.
//

#include <MyScene/tool/SceneReflectionInit.h>

#include <MyScene/core/core>

#include <MyDP/Reflection/Reflection.h>

using namespace My;

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

  Reflection<Component>::Instance().SetName("My::Component");

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

  Reflection<Cmpt::Transform>::Instance()
      .SetName("My::Cmpt::Transform")
      .Regist(&Cmpt::Transform::pos, "pos")
      .Regist(&Cmpt::Transform::scale, "scale")
      .Regist(&Cmpt::Transform::rot, "rot")
      .RegistConstructor([](SObj* sobj) {
        auto [cmpt] = sobj->Attach<Cmpt::Transform>();
        return cmpt;
      });

  // =================== Light ===================

  Reflection<Light>::Instance().SetName("My::Light").RegistConstructor();

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

  Reflection<Plane>::Instance().SetName("My::Plane").RegistConstructor();

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

  Reflection<Image>::Instance()
      .SetName("My::Image")
      .Regist(&Image::width, "width")
      .Regist(&Image::height, "height")
      .Regist(&Image::channel, "channel")
      .Regist(&Image::path, "path")
      .RegistConstructor();
}