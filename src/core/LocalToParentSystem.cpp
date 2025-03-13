//
// Created by Admin on 13/03/2025.
//

#include <MyScene/Systems/LocalToParentSystem.h>
#include <MyScene/Systems/TRSToLocalToWorldSystem.h>

#include <MyScene/Components/Children.h>
#include <MyScene/Components/LocalToParent.h>
#include <MyScene/Components/LocalToWorld.h>
#include <MyScene/Components/Parent.h>
#include <MyScene/Systems/TRSToLocalToParentSystem.h>

using namespace My::MyScene;

void LocalToParentSystem::ChildLocalToWorld(const transformf& parent_l2w,
                                            MyECS::Entity e) {
  transformf l2w;
  auto w = GetWorld();
  if (w->entityMngr.Have<LocalToWorld>(e) &&
      w->entityMngr.Have<LocalToParent>(e)) {
    auto child_l2w = w->entityMngr.Get<LocalToWorld>(e);
    auto child_l2p = w->entityMngr.Get<LocalToParent>(e);
    l2w = parent_l2w * child_l2p->value;
    child_l2w->value = l2w;
  } else
    l2w = parent_l2w;

  if (w->entityMngr.Have<Children>(e)) {
    auto children = w->entityMngr.Get<Children>(e);
    for (const auto& child : children->value)
      ChildLocalToWorld(l2w, e);
  }
}

void LocalToParentSystem::OnUpdate(MyECS::Schedule& schedule) {
  MyECS::EntityFilter rootFilter{
      TypeList<>{},       // all
      TypeList<>{},       // any
      TypeList<Parent>{}  // none
  };

  schedule
      .InsertNone(TRSToLocalToWorldSystem::SystemFuncName,
                  MyECS::CmptType::Of<Parent>)
      .Register(
          [this](const LocalToWorld* l2w, const Children* children) {
            for (const auto& child : children->value)
              ChildLocalToWorld(l2w->value, child);
          },
          SystemFuncName, rootFilter)
      .Order(TRSToLocalToParentSystem::SystemFuncName, SystemFuncName);
}
