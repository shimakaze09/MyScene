//
// Created by Admin on 27/02/2025.
//

#include <MyScene/core/Light/EnvLight.h>

#include <MyScene/core/Material/Texture2D.h>

#include "detail/dynamic_reflection/EnvLight.inl"

#include <MyGM/sample.h>

using namespace My;
using namespace std;

EnvLight::EnvLight(float intensity, const rgbf& color, Texture2D* texture)
    : intensity{intensity}, color{color}, texture{texture} {}

rgbf EnvLight::Radiance(const pointf2& uv) const noexcept {
  if (!texture)
    return RadianceFactor();

  return RadianceFactor() * texture->Sample(uv).to_rgb();
}

rgbf EnvLight::Radiance(const vecf3& dir) const noexcept {
  return RadianceFactor() *
         Radiance(dir.normalize().cast_to<normalf>().to_sphere_texcoord());
}

tuple<rgbf, vecf3, float> EnvLight::Sample() const noexcept {
  // TODO
  vecf3 wi = uniform_on_sphere<float>().cast_to<vecf3>();
  return {Radiance(wi), wi, 1 / (4 * PI<float>)};
}

tuple<rgbf, vecf3, float> EnvLight::Sample(const normalf& n) const noexcept {
  assert(n.is_normalized());
  auto vn = n.cast_to<vecf3>();
  svecf s_wi = cos_weighted_on_hemisphere<float>().cast_to<svecf>();
  vecf3 t{1, 0, 0};
  t = (t - t.dot(vn) * vn).normalize();
  vecf3 b = vn.cross(t);
  vecf3 wi = svecf::TBN(vn, t) * s_wi;
  return {Radiance(wi), wi, s_wi.cos_stheta() / PI<float>};
}

float EnvLight::PDF(const vecf3& dir) const noexcept {
  return 1 / (4 * PI<float>);
}

void EnvLight::OnRegist() {
  detail::dynamic_reflection::ReflRegist_EnvLight();
}
