//
// Created by Admin on 28/02/2025.
//

#pragma once
#pragma warning(disable : 5030)

#include <MyDP/Reflection/ReflectionBase.h>

namespace My {
struct ReflAttr {
  static constexpr char default_value[] =
      "null";  // ReflectionBase::Meta::default_value
  static constexpr char read_only[] =
      "read_only";  // ReflectionBase::Meta::read_only
  static constexpr const char not_serialize[] = "not_serialize";
  static constexpr const char not_UI[] = "not_UI";
};
}  // namespace My
