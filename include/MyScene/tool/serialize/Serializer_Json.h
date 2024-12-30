//
// Created by Admin on 30/12/2024.
//

#include <MyScene/tool/serialize/ISerializer.h>

#include <MyGM/MyGM>
#include <MyScene/core/core>

#include <MyDP/Reflection/Reflection.h>
#include <MyDP/Reflection/VarPtrVisitor.h>

#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

namespace My {
class Serializer_Json : public ISerializer,
                        public VarPtrVisitor<Serializer_Json> {
 public:
  Serializer_Json();

  using VarPtrVisitor<Serializer_Json>::Regist;
  using ReflTraitsVisitor::Visit;

  virtual std::string Serialize(const Scene* scene) override;
  virtual std::string Serialize(const SObj* sobj) override;

  template <typename Func>
  void RegistSerializeOtherMember(Func&& func);

  rapidjson::Writer<rapidjson::StringBuffer>& GetWriter() { return writer; }

 protected:
  template <typename T>
  void SerializeObj(const T* p);

  template <typename T>
  void SerializeOtherMember(const T* p);

  template <typename T>
  void ImplVisit(T* const& obj) {
    SerializeObj(obj);
  }

  template <typename T>
  void ImplVisit(const std::set<T*>& p);
  void ImplVisit(const std::string& p);

  template <typename T>
  void SerializeArray(const T& arr);

  void ImplVisit(const bool& val);

  void ImplVisit(const float& val);
  void ImplVisit(const double& val);

  void ImplVisit(const int8_t& val);
  void ImplVisit(const int16_t& val);
  void ImplVisit(const int32_t& val);
  void ImplVisit(const int64_t& val);

  void ImplVisit(const uint8_t& val);
  void ImplVisit(const uint16_t& val);
  void ImplVisit(const uint32_t& val);
  void ImplVisit(const uint64_t& val);

  template <typename T, size_t N>
  void ImplVisit(const val<T, N>& val);

  template <typename T, size_t N>
  void ImplVisit(const vec<T, N>& val);

  template <typename T, size_t N>
  void ImplVisit(const point<T, N>& val);

  template <typename T, size_t N>
  void ImplVisit(const scale<T, N>& val);

  template <typename T>
  void ImplVisit(const rgb<T>& val);

  template <typename T>
  void ImplVisit(const rgba<T>& val);

  template <typename T>
  void ImplVisit(const quat<T>& val);

  template <typename T>
  void ImplVisit(const euler<T>& val);

  template <typename T>
  void ImplVisit(const normal<T>& val);

  template <typename T, size_t N>
  void ImplVisit(const mat<T, N>& val);

  template <typename T>
  void ImplVisit(const Ubpa::transform<T>& val);

 private:
  virtual void Receive(
      const std::string& name,
      const std::map<std::string, std::shared_ptr<const VarPtrBase>>& nv)
      override;

 private:
  rapidjson::StringBuffer buffer;
  rapidjson::Writer<rapidjson::StringBuffer> writer;
  std::map<size_t, std::function<void(const void*)>> callbacks;
};
}  // namespace My

#include "detail/Serializer_Json.inl"
