//
// Created by Admin on 30/12/2024.
//

#pragma once

#include "IDeserializer.h"

#include <MyDP/Reflection/Reflection.h>
#include <MyDP/Reflection/VarPtrVisitor.h>

#include <MyGM/MyGM.h>

#include <functional>
#include <map>
#include <string>

namespace My {
class MyJsonValue;
class MyJsonDoc;

class DeserializerJSON : public IDeserializer,
                         public VarPtrVisitor<DeserializerJSON> {
 public:
  DeserializerJSON();

  virtual Scene* DeserializeScene(const std::string& json) override;
  virtual SObj* DeserializeSObj(const std::string& json) override;

 protected:
  template <typename T>
  void ImplVisit(T*& obj);

  template <typename T>
  void ImplVisit(T& property);

  template <typename T, size_t N>
  void ImplVisit(val<T, N>& val);

  template <typename T, size_t N>
  void ImplVisit(vec<T, N>& val);

  template <typename T, size_t N>
  void ImplVisit(point<T, N>& val);

  template <typename T, size_t N>
  void ImplVisit(scale<T, N>& val);

  template <typename T>
  void ImplVisit(rgb<T>& val);

  template <typename T>
  void ImplVisit(rgba<T>& val);

  template <typename T>
  void ImplVisit(quat<T>& val);

  template <typename T>
  void ImplVisit(euler<T>& val);

  template <typename T>
  void ImplVisit(normal<T>& val);

  template <typename T, size_t N>
  void ImplVisit(mat<T, N>& val);

  template <typename T>
  void ImplVisit(My::transform<T>& val);

  void ImplVisit(std::string& val);

 private:
  Scene* ParseScene(const MyJsonDoc* doc);
  void ParseSObj(Scene* scene, SObj* sobj, const MyJsonValue* value);
  void* ParseObj(const MyJsonValue* value);
  void ParseObj(void* obj, const MyJsonValue* value);

  // for visitor
  const MyJsonValue* cur{nullptr};
  void* rstObj{nullptr};

  template <typename Func>
  void RegisterGenObj(Func&& func);

  // dynamic
  std::map<std::string, std::function<void*(const MyJsonValue* obj)>> type2func;
};
}  // namespace My
