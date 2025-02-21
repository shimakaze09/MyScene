//
// Created by Admin on 21/02/2025.
//

#pragma once

#include <MyTemplate/Concept.h>

namespace My::detail::SystemMngr_ {
template <typename T>
Concept(HaveOnUpdate, &T::OnUpdate);

template <typename Cmpt>
struct UpdateFunc;
}  // namespace My::detail::SystemMngr_

namespace My {
template <typename Cmpt>
void SystemMngr::Regist() {
  if constexpr (Require<detail::SystemMngr_::HaveOnUpdate, Cmpt>) {
    if (OnUpdates.find(TypeID<Cmpt>) == OnUpdates.end()) {
      auto func = detail::SystemMngr_::UpdateFunc<Cmpt>::run();
      OnUpdates[TypeID<Cmpt>] = [this, func](World* world) {
        world->ParallelEach(func);
      };
    }
  }
}
}  // namespace My

namespace My::detail::SystemMngr_ {
template <typename Cmpt, typename ArgList>
struct UpdateFuncHelper;

template <typename Cmpt, typename... Cmpts>
struct UpdateFuncHelper<Cmpt, TypeList<Cmpts...>> {

  static auto run() noexcept {
    return [](Cmpt* cmpt, Cmpts... cmpts) {
      cmpt->OnUpdate(cmpts...);
    };
  }
};

template <typename Cmpt>
struct UpdateFunc {
  static_assert(Require<HaveOnUpdate, Cmpt>);
  using ArgList = FuncTraits_ArgList<decltype(&Cmpt::OnUpdate)>;

  static auto run() noexcept { return UpdateFuncHelper<Cmpt, ArgList>::run(); }
};
}  // namespace My::detail::SystemMngr_
