//
// Created by Admin on 26/02/2025.
//

#include <MyScene/core/Material/Texture2D.h>

#include <MyBL/RsrcMngr.h>

using namespace My;
using namespace std;

Texture2D::Texture2D(const std::string& path)
    : path{path}, img{RsrcMngr<Image>::Instance().GetOrCreate(path)} {}

void Texture2D::SetPath(const string& path) {
  this->path = path;
  img = RsrcMngr<Image>::Instance().GetOrCreate(path);
}

rgbaf Texture2D::Sample(pointf2 uv) {
  // transform uv
  WrapMode wrapmodes[2] = {wrap_u, wrap_v};
  bool inv[2] = {inv_u, inv_v};
  for (size_t i = 0; i < 2; i++) {
    switch (wrapmodes[i]) {
      case Ubpa::Texture2D::WrapMode::Clamp:
        uv[i] = std::clamp(uv[i], 0.f, 1.f);
        break;
      case Ubpa::Texture2D::WrapMode::Repeat:
        uv[i] -= std::floor(uv[i]);
        break;
      case Ubpa::Texture2D::WrapMode::Mirror:
        uv[i] = 1 - std::abs(uv[i] - 1 - std::floor(uv[i] / 2));
        break;
    }
    if (inv_u)
      uv[i] = 1 - uv[i];
  }

  if (swap_uv)
    swap(uv[0], uv[1]);

  // sample
  return img->Sample(uv);
}
