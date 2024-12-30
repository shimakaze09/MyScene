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
      .Regist(&Scene::root, "root");

  // =================== Component ===================

  Reflection<Component>::Instance().SetName("My::Component");

  Reflection<Cmpt::Camera>::Instance()
      .SetName("My::Cmpt::Camera")
      .Regist(&Cmpt::Camera::ar, "ar")
      .Regist(&Cmpt::Camera::fov, "fov");

  Reflection<Cmpt::Geometry>::Instance()
      .SetName("My::Cmpt::Geometry")
      .Regist(&Cmpt::Geometry::primitive, "primitive");

  Reflection<Cmpt::Light>::Instance()
      .SetName("My::Cmpt::Light")
      .Regist(&Cmpt::Light::light, "light");

  Reflection<Cmpt::Material>::Instance()
      .SetName("My::Cmpt::Material")
      .Regist(&Cmpt::Material::material, "material");

  Reflection<Cmpt::Transform>::Instance()
      .SetName("My::Cmpt::Transform")
      .Regist(&Cmpt::Transform::pos, "pos")
      .Regist(&Cmpt::Transform::scale, "scale")
      .Regist(&Cmpt::Transform::rot, "rot");

  // =================== Light ===================

  Reflection<Light>::Instance().SetName("My::Light");

  Reflection<PointLight>::Instance()
      .SetName("My::PointLight")
      .Regist(&PointLight::intensity, "intensity")
      .Regist(&PointLight::color, "color");

  // =================== Primitive ===================

  Reflection<Primitive>::Instance().SetName("My::Primitive");

  Reflection<Sphere>::Instance().SetName("My::Sphere");

  // =================== Material ===================

  Reflection<Material>::Instance().SetName("My::Material");

  Reflection<Diffuse>::Instance()
      .SetName("My::Diffuse")
      .Regist(&Diffuse::albedo, "albedo");
}