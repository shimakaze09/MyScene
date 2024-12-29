//
// Created by Admin on 29/12/2024.
//

#pragma once

#include <functional>
#include <type_traits>

namespace My::detail::UScene {
template <typename T>
class Dirty {
 public:
  static_assert(std::is_default_constructible_v<T>);

  Dirty(std::function<void(T& t)> update) : update{update} {}

  void SetDirty() { dirty = true; }

  const T& Get() const {
    if (dirty) {
      dirty = false;
//      update(t);
    }
    return t;
  }

  operator T() const { return Get(); }

 private:
  const std::function<void(T& t)> update;
  mutable bool dirty{true};
  mutable T t;
};
}  // namespace My::detail::UScene