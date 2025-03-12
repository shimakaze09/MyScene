//
// Created by Admin on 29/12/2024.
//

#include <MySTL/tuple.h>

#include <iostream>

int main() {
  constexpr auto acc = My::MySTL::tuple_accumulate<true, false, true>(
      std::tuple{1, 2, 3}, 6, [](auto&& acc, auto i) { return acc + i; });
  static_assert(acc == 10);

  My::MySTL::tuple_for_each<true, false, true>(
      std::tuple{1, 2, 3}, [](auto i) { std::cout << i << std::endl; });

  constexpr auto idx = My::MySTL::tuple_find_if(
      std::tuple{1, 2, 3}, [](auto i) { return i % 2 == 0; });
  static_assert(idx == 1);

  constexpr auto idx2 = My::MySTL::tuple_find(std::tuple{1, 2, 3}, 3);
  static_assert(idx2 == 2);

  constexpr auto cnt = My::MySTL::tuple_count_if(std::tuple{1, 2, 3},
                                                 [](auto e) { return e >= 2; });
  static_assert(cnt == 2);

  constexpr auto cnt2 = My::MySTL::tuple_count(std::tuple{1, 2, 3}, 3);
  static_assert(cnt2 == 1);

  constexpr auto appendedTuple =
      My::MySTL::tuple_append(std::tuple{1, 2, 3}, 4, 5);
  static_assert(std::get<3>(appendedTuple) == 4);
  static_assert(std::get<4>(appendedTuple) == 5);

  constexpr auto prependedTuple =
      My::MySTL::tuple_prepend(std::tuple{1, 2, 3}, -1, 0);
  static_assert(std::get<0>(prependedTuple) == -1);
  static_assert(std::get<1>(prependedTuple) == 0);
}
