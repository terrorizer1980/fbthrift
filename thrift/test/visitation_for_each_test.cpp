/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/test/gen-cpp2/reflection_for_each_field.h> // @manual=:reflection_if-cpp2-visitation
#include <thrift/test/gen-cpp2/reflection_no_metadata_for_each_field.h> // @manual=:reflection_no_metadata_if-cpp2-visitation

#include <folly/Overload.h>
#include <folly/functional/Invoke.h>
#include <folly/portability/GTest.h>

#include <typeindex>

using namespace std;
using namespace apache::thrift;

namespace test_cpp2 {
namespace cpp_reflection {

TEST(struct1, test_metadata) {
  struct1 s;
  for_each_field(s, [i = 0](auto ref, auto&& meta) mutable {
    EXPECT_EQ(meta.id, i + 1);
    EXPECT_EQ(meta.name, "field" + to_string(i));
    EXPECT_EQ(
        meta.type.getType(),
        (vector{
            meta.type.t_primitive,
            meta.type.t_primitive,
            meta.type.t_enum,
            meta.type.t_enum,
            meta.type.t_union,
            meta.type.t_union,
        })[i]);
    EXPECT_EQ(
        meta.is_optional, (vector{false, true, false, false, true, false})[i]);
    EXPECT_EQ(
        type_index(typeid(ref)),
        (vector<type_index>{
            typeid(required_field_ref<int32_t&>),
            typeid(optional_field_ref<string&>),
            typeid(field_ref<enum1&>),
            typeid(required_field_ref<enum2&>),
            typeid(optional_field_ref<union1&>),
            typeid(field_ref<union2&>),
        })[i]);

    // required field always has value
    EXPECT_EQ(
        ref.has_value(), (vector{true, false, false, true, false, false})[i]);
    ++i;
  });
}

TEST(struct1, modify_field) {
  struct1 s;
  s.field0_ref() = 10;
  s.field1_ref() = "20";
  s.field2_ref() = enum1::field0;
  s.field3_ref() = enum2::field1_2;
  s.field4_ref().emplace().set_us("foo");
  s.field5_ref().emplace().set_us_2("bar");
  auto run = folly::overload(
      [](int32_t& ref) {
        EXPECT_EQ(ref, 10);
        ref = 20;
      },
      [](string& ref) {
        EXPECT_EQ(ref, "20");
        ref = "30";
      },
      [](enum1& ref) {
        EXPECT_EQ(ref, enum1::field0);
        ref = enum1::field1;
      },
      [](enum2& ref) {
        EXPECT_EQ(ref, enum2::field1_2);
        ref = enum2::field2_2;
      },
      [](union1& ref) {
        EXPECT_EQ(ref.get_us(), "foo");
        ref.set_ui(20);
      },
      [](union2& ref) {
        EXPECT_EQ(ref.get_us_2(), "bar");
        ref.set_ui_2(30);
      },
      [](auto&) { EXPECT_TRUE(false) << "type mismatch"; });
  for_each_field(s, [run](auto ref, auto&&) {
    EXPECT_TRUE(ref.has_value());
    run(*ref);
  });
  EXPECT_EQ(s.field0_ref(), 20);
  EXPECT_EQ(s.field1_ref(), "30");
  EXPECT_EQ(s.field2_ref(), enum1::field1);
  EXPECT_EQ(s.field3_ref(), enum2::field2_2);
  EXPECT_EQ(s.field4_ref()->get_ui(), 20);
  EXPECT_EQ(s.field5_ref()->get_ui_2(), 30);
}

TEST(hasRefUnique, test_cpp_ref_unique) {
  hasRefUnique s;
  deque<string> names = {
      "aStruct",
      "aList",
      "aSet",
      "aMap",
      "aUnion",
      "anOptionalStruct",
      "anOptionalList",
      "anOptionalSet",
      "anOptionalMap",
      "anOptionalUnion",
  };
  for_each_field(s, [&, i = 0](auto&& ref, auto&& meta) mutable {
    EXPECT_EQ(meta.name, names[i++]);
    if constexpr (std::is_same_v<decltype(*ref), deque<string>&>) {
      if (meta.is_optional) {
        ref.reset(new decltype(names)(names));
      }
    }
  });

  // for cpp.ref, unqualified field has value by default
  EXPECT_TRUE(s.aStruct_ref());
  EXPECT_TRUE(s.aList_ref()->empty());
  EXPECT_TRUE(s.aSet_ref()->empty());
  EXPECT_TRUE(s.aMap_ref()->empty());
  EXPECT_TRUE(s.aUnion_ref());

  EXPECT_FALSE(s.anOptionalStruct_ref());
  EXPECT_EQ(*s.anOptionalList_ref(), names);
  EXPECT_FALSE(s.anOptionalSet_ref());
  EXPECT_FALSE(s.anOptionalMap_ref());
  EXPECT_FALSE(s.anOptionalUnion_ref());
}

} // namespace cpp_reflection
} // namespace test_cpp2

namespace test_cpp2 {
namespace cpp_reflection_no_metadata {

TEST(struct1_no_metadata, test_metadata) {
  struct1 s;
  for_each_field(s, [i = 0](auto ref, auto&& meta) mutable {
    EXPECT_EQ(meta.id, 0);
    EXPECT_EQ(meta.name, "");
    EXPECT_EQ(int(meta.type.getType()), 0);
    EXPECT_EQ(meta.is_optional, false);
    EXPECT_EQ(
        type_index(typeid(ref)),
        (vector<type_index>{
            typeid(required_field_ref<int32_t&>),
            typeid(optional_field_ref<string&>),
            typeid(field_ref<enum1&>),
            typeid(required_field_ref<enum2&>),
            typeid(optional_field_ref<union1&>),
            typeid(field_ref<union2&>),
        })[i]);

    // required field always has value
    EXPECT_EQ(
        ref.has_value(), (vector{true, false, false, true, false, false})[i]);
    ++i;
  });
}

TEST(struct1_no_metadata, modify_field) {
  struct1 s;
  s.field0_ref() = 10;
  s.field1_ref() = "20";
  s.field2_ref() = enum1::field0;
  s.field3_ref() = enum2::field1_2;
  s.field4_ref().emplace().set_us("foo");
  s.field5_ref().emplace().set_us_2("bar");
  auto run = folly::overload(
      [](int32_t& ref) {
        EXPECT_EQ(ref, 10);
        ref = 20;
      },
      [](string& ref) {
        EXPECT_EQ(ref, "20");
        ref = "30";
      },
      [](enum1& ref) {
        EXPECT_EQ(ref, enum1::field0);
        ref = enum1::field1;
      },
      [](enum2& ref) {
        EXPECT_EQ(ref, enum2::field1_2);
        ref = enum2::field2_2;
      },
      [](union1& ref) {
        EXPECT_EQ(ref.get_us(), "foo");
        ref.set_ui(20);
      },
      [](union2& ref) {
        EXPECT_EQ(ref.get_us_2(), "bar");
        ref.set_ui_2(30);
      },
      [](auto&) { EXPECT_TRUE(false) << "type mismatch"; });
  for_each_field(s, [run](auto ref, auto&&) {
    EXPECT_TRUE(ref.has_value());
    run(*ref);
  });
  EXPECT_EQ(s.field0_ref(), 20);
  EXPECT_EQ(s.field1_ref(), "30");
  EXPECT_EQ(s.field2_ref(), enum1::field1);
  EXPECT_EQ(s.field3_ref(), enum2::field2_2);
  EXPECT_EQ(s.field4_ref()->get_ui(), 20);
  EXPECT_EQ(s.field5_ref()->get_ui_2(), 30);
}

} // namespace cpp_reflection_no_metadata
} // namespace test_cpp2
