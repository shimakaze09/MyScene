//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "Primitive.h"
#include "Triangle.h"

#include <MyBL/Pool.h>
#include <MyDP/Basic/Read.h>
#include <MyGM/UGM.h>

#include <vector>

namespace My {
class TriMesh : public Primitive {
 public:
  [[not_UI]]
  Read<TriMesh, std::vector<valu3>> indices;  // unsigned is for OpenGL
  [[not_UI]]
  Read<TriMesh, std::vector<pointf3>> positions;
  [[not_UI]]
  Read<TriMesh, std::vector<pointf2>> texcoords;
  [[not_UI]]
  Read<TriMesh, std::vector<normalf>> normals;
  [[not_UI]]
  Read<TriMesh, std::vector<vecf3>> tangents;
  [[not_serialize, not_UI]]
  Read<TriMesh, std::vector<const Triangle*>> triangles;

  TriMesh() = default;

  TriMesh(const std::vector<valu3>& indices,
          const std::vector<pointf3>& positions,
          const std::vector<pointf2>& texcoords = std::vector<pointf2>(),
          const std::vector<normalf>& normals = std::vector<normalf>(),
          const std::vector<vecf3>& tangents = std::vector<vecf3>());

  enum class Type { Cube, Sphere, Square };
  TriMesh(Type type);

  // center : (0, 0, 0), side length: 2
  void InitCubeMesh();
  // 50 x 50 grid
  void InitSphereMesh();
  // center : (0, 0, 0), side length: 2, normal: (0, 1, 0)
  void InitSquareMesh();

  bool Init(const std::vector<valu3>& indices,
            const std::vector<pointf3>& positions,
            const std::vector<pointf2>& texcoords = std::vector<pointf2>(),
            const std::vector<normalf>& normals = std::vector<normalf>(),
            const std::vector<vecf3>& tangents = std::vector<vecf3>());

  bool Empty() const noexcept;

  void Clear();

  void GenNormals();
  void GenTangents();

  static void OnRegist();

 private:
  Pool<Triangle> triPool;
};
}  // namespace My
