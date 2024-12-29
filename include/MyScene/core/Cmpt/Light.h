//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "../Component.h"

namespace My {
class Light;
}

namespace My::Cmpt {

class Light : public Component {
 public:
  My::Light* const volatile light{nullptr};

  void SetLight(My::Light* light) {
    delete this->light;
    const_cast<My::Light*&>(this->light) = light;
  }
};
}  // namespace My::Cmpt
