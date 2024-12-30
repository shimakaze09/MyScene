//
// Created by Admin on 29/12/2024.
//

#pragma once

#include "../Component.h"

#include <MyGM/transform.h>

#include <MyDP/Basic/Dirty.h>
#include <MyDP/Basic/Read.h>

namespace My::Cmpt {
class Transform : public Component {
 public:
  Read<Transform, pointf3> pos{0.f};
  Read<Transform, scalef3> scale{1.f};
  Read<Transform, quatf> rot{quatf::identity()};

  Dirty<transformf> tsfm;

  void SetPosition(const pointf3& pos);
  void SetScale(const scalef3& scale);
  void SetRotation(const quatf& rot);

  void Init(const pointf3& pos = pointf3{0.f},
            const scalef3& scale = scalef3{1.f},
            const quatf& rot = quatf::identity());

  const transformf GetLocalToWorldMatrix() const;

  const pointf3 GetWorldPos() const {
    return GetLocalToWorldMatrix().decompose_position();
  }

  Transform();
  Transform(Transform&& tsfm) = default;
};
}  // namespace My::Cmpt