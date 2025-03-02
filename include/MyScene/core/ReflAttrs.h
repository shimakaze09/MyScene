//
// Created by Admin on 28/02/2025.
//

#pragma once
#pragma warning(disable : 5030)

#include <MyDP/Reflection/ReflectionBase.h>

namespace My {
struct ReflAttr {
  static constexpr std::string_view default_value =
      ReflectionBase::Meta::default_value;
  static constexpr std::string_view read_only = ReflectionBase::Meta::read_only;
  static constexpr std::string_view not_serialize = "not_serialize";
  static constexpr std::string_view serialize_kernel =
      "serialize_kernel";  // must be string
  static constexpr std::string_view not_UI = "not_UI";
  static constexpr std::string_view range = "range";
};
}  // namespace My
