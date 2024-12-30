//
// Created by Admin on 30/12/2024.
//

#pragma once

namespace My {
template <typename Func>
void SerializerJSON::RegistSerializeOtherMember(Func&& func) {
  using CTP = Front_t<FuncTraits_ArgList<Func>>;
  static_assert(std::is_pointer_v<CTP>, "arguments must be const T*");
  using CT = std::remove_pointer_t<CTP>;
  static_assert(std::is_const_v<CT>, "arguments must be const T*");
  using T = std::remove_const_t<CT>;
  callbacks[TypeID<T>] = [func = std::forward<Func>(func)](const void* obj) {
    func(reinterpret_cast<CTP>(obj));
  };
}
}  // namespace My
