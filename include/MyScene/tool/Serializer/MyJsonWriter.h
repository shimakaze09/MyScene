//
// Created by Admin on 21/02/2025.
//

#pragma once

#include <memory>
#include <string>

namespace My {
class MyJsonWriter {
 public:
  MyJsonWriter();
  ~MyJsonWriter();
  MyJsonWriter(MyJsonWriter&& myJson) noexcept;
  MyJsonWriter& operator=(MyJsonWriter&& myJson) noexcept;

  void Clear();
  std::string Rst() const;

  void Key(const char* str);

  void Null();
  void Bool(bool v);
  void Double(double v);
  void Int(int v);
  void Int64(std::int64_t v);
  void Uint(unsigned int v);
  void Uint64(std::uint64_t v);
  void String(const char* str);

  void StartObject();
  void EndObject();
  void StartArray();
  void EndArray();

 private:
  struct Impl;

  Impl* PImpl() { return pImpl.get(); }

  const Impl* PImpl() const { return pImpl.get(); }

  std::unique_ptr<Impl> pImpl;
};
}  // namespace My
