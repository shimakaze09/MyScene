//
// Created by Admin on 29/12/2024.
//

#pragma once

namespace My {
class SObj;

class Component {
 public:
  Component() = default;
  virtual ~Component() = default;

  SObj* GetSObj() { return sobj; }

  const SObj* GetSObj() const { return sobj; }

 private:
  SObj* sobj{nullptr};
  friend class SObj;
};
}  // namespace My
