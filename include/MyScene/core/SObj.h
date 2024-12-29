//
// Created by Admin on 29/12/2024.
//

#pragma once

#include <MyECS/cmpt/Node.h>

#include <MyGM/transform.h>

#include <string>

namespace My::Cmpt {
class SObj : public Node<SObj> {
 public:
  std::string name;

  using Node<SObj>::Node;

  const transformf GetLocalToWorldMatrix() const;

  const pointf3 GetWorldPos() const {
    return GetLocalToWorldMatrix().decompose_position();
  }
};
}  // namespace My::Cmpt
