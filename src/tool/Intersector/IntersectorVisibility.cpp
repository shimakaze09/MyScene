//
// Created by Admin on 17/02/2025.
//

#include <MyScene/tool/Intersector/IntersectorVisibility.h>

#include <MyScene/tool/Accel/BVH.h>
#include <MyScene/core/core>

#include <MyGM/UGM>

#include <stack>

using namespace My;
using namespace std;

IntersectorVisibility::IntersectorVisibility()
    : isIntersect{false}, r{rayf3{pointf3{}, vecf3{}}} {
  RegistC<Square, Sphere, Triangle>();
}

bool IntersectorVisibility::Visit(const BVH* bvh, const rayf3& _r) const {
  // init
  r = _r;
  isIntersect = false;

  // backup
  const pointf3 pnt = r.point();
  const vecf3 dir = r.dir();

  const bool dirIsNeg[3] = {dir[0] < 0, dir[1] < 0, dir[2] < 0};

  stack<size_t> nodeIdxStack;
  nodeIdxStack.push(0);
  while (!nodeIdxStack.empty()) {
    const auto nodeIdx = nodeIdxStack.top();
    nodeIdxStack.pop();
    const auto& node = bvh->GetNode(nodeIdx);
    auto [isIntersectBox, t0, t1] = r.intersect(node.GetBox());
    if (!isIntersectBox)
      continue;

    if (node.IsLeaf()) {
      for (auto primitiveIdx : node.PrimitiveIndices()) {
        auto primitive = bvh->GetPrimitive(primitiveIdx);

        r = bvh->GetW2L(primitive) * r;
        Visit(primitive);

        if (isIntersect)
          return false;

        // restore
        r.point() = pnt;
        r.dir() = dir;
      }
    } else {
      size_t firstChildIdx = LinearBVHNode::FirstChildIdx(nodeIdx);
      size_t secondChildIdx = node.GetSecondChildIdx();
      if (dirIsNeg[static_cast<size_t>(node.GetAxis())]) {
        nodeIdxStack.push(firstChildIdx);
        nodeIdxStack.push(secondChildIdx);  // on top
      } else {
        nodeIdxStack.push(secondChildIdx);
        nodeIdxStack.push(firstChildIdx);  // on top
      }
    }
  }

  return true;
}

void IntersectorVisibility::ImplVisit(const Square* primitive) {
  auto [isIntersect, t, hitPos] = r.intersect_std_square();
  this->isIntersect = isIntersect;
}

void IntersectorVisibility::ImplVisit(const Sphere* primitive) {
  auto [isIntersect, t] = r.intersect_std_sphere();
  this->isIntersect = isIntersect;
}

void IntersectorVisibility::ImplVisit(const Triangle* primitive) {
  auto mesh = primitive->mesh;
  auto p0 = mesh->positions->at(primitive->indices[0]);
  auto p1 = mesh->positions->at(primitive->indices[1]);
  auto p2 = mesh->positions->at(primitive->indices[2]);
  trianglef3 tri{p0, p1, p2};
  auto [isIntersect, wuv, t] = r.intersect(tri);
  this->isIntersect = isIntersect;
}
