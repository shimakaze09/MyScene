//
// Created by Admin on 28/02/2025.
//

#include <MyScene/core/Material/stdBRDF.h>

#include "detail/dynamic_reflection/stdBRDF.inl"

using namespace My;

void stdBRDF::OnRegist() {
  detail::dynamic_reflection::ReflRegist_stdBRDF();
}
