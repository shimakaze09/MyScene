//
// Created by Admin on 21/02/2025.
//

#include <MyScene/tool/Serializer/MyJsonWriter.h>

#include "../_deps/rapidjson/stringbuffer.h"
#include "../_deps/rapidjson/writer.h"

using namespace My;
using namespace std;

struct MyJsonWriter::Impl {
  rapidjson::StringBuffer buffer;
  rapidjson::Writer<rapidjson::StringBuffer> writer;
};

MyJsonWriter::~MyJsonWriter() = default;
MyJsonWriter::MyJsonWriter(MyJsonWriter&& myJson) noexcept = default;
MyJsonWriter& MyJsonWriter::operator=(MyJsonWriter&& myJson) noexcept = default;

MyJsonWriter::MyJsonWriter() : pImpl(make_unique<MyJsonWriter::Impl>()) {}

void MyJsonWriter::Clear() {
  PImpl()->buffer.Clear();
  PImpl()->writer.Reset(PImpl()->buffer);
}

string MyJsonWriter::Rst() const {
  return PImpl()->buffer.GetString();
}

void MyJsonWriter::Key(const char* str) {
  PImpl()->writer.Key(str);
}

void MyJsonWriter::Null() {
  PImpl()->writer.Null();
}

void MyJsonWriter::Bool(bool v) {
  PImpl()->writer.Bool(v);
}

void MyJsonWriter::Double(double v) {
  PImpl()->writer.Double(v);
}

void MyJsonWriter::Int(int v) {
  PImpl()->writer.Int(v);
}

void MyJsonWriter::Int64(std::int64_t v) {
  PImpl()->writer.Int64(v);
}

void MyJsonWriter::Uint(unsigned int v) {
  PImpl()->writer.Uint(v);
}

void MyJsonWriter::Uint64(std::uint64_t v) {
  PImpl()->writer.Uint64(v);
}

void MyJsonWriter::String(const char* str) {
  PImpl()->writer.String(str);
}

void MyJsonWriter::StartObject() {
  PImpl()->writer.StartObject();
}

void MyJsonWriter::EndObject() {
  PImpl()->writer.EndObject();
}

void MyJsonWriter::StartArray() {
  PImpl()->writer.StartArray();
}

void MyJsonWriter::EndArray() {
  PImpl()->writer.EndArray();
}
