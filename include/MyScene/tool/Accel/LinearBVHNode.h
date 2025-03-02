//
// Created by Admin on 17/02/2025.
//

#pragma once

#include <MyGM/bbox.h>

namespace My {
class LinearBVHNode {
 public:
  void InitLeaf(const bboxf3& box, int shapesOffset, int shapesNum);
  void InitBranch(const bboxf3& box, int secondChildIdx, Axis axis);

 public:
  const bboxf3& GetBox() const noexcept { return box; }

  bool IsLeaf() const noexcept { return shapesNum != 0; }

  const std::vector<size_t> PrimitiveIndices() const;

  static size_t FirstChildIdx(size_t nodeIdx) noexcept { return nodeIdx + 1; }

  size_t GetSecondChildIdx() const noexcept {
    assert(!IsLeaf());
    return secondChildIdx;
  }

  Axis GetAxis() const noexcept {
    assert(!IsLeaf());
    return axis;
  }

 private:
  bboxf3 box;

  union {
    uint32_t shapesOffset;    // leaf
    uint32_t secondChildIdx;  // interior
  };

  uint16_t shapesNum;
  Axis axis;
  const uint8_t pad[1]{0};  // ensure 32 byte total size
};

static_assert(sizeof(LinearBVHNode) == 32);
}  // namespace My
