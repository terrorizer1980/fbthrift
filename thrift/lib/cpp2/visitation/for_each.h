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

#pragma once

#include <folly/Traits.h>
#include <thrift/lib/cpp2/reflection/reflection.h>
#include <thrift/lib/cpp2/visitation/metadata.h>

namespace apache {
namespace thrift {
/**
 * for_each_field iterates over fields in thrift struct. Example:
 *
 *   for_each_field(thriftObject, [](auto field_ref, const ThriftField& meta) {
 *     LOG(INFO) << meta.name << " --> " << *field_ref;
 *   });
 *
 * ThriftField schema is defined here: https://git.io/JJQpY
 * If there are mixin fields, inner fields won't be iterated.
 * If `no_metadata` thrift option is enabled, ThriftField will be empty.
 *
 * @param t thrift object
 * @param f a callable that will be called for each thrift field
 */
template <typename T, typename F>
void for_each_field(T&& t, F&& f) {
  using type = folly::remove_cvref_t<T>;
  using meta = reflect_struct<type>;
  fatal::foreach<typename meta::members>([&](auto tag) {
    using mtype = decltype(fatal::tag_type(tag));
    auto&& ref = typename mtype::field_ref_getter()(static_cast<T&&>(t));
    static_cast<F&&>(f)(ref, detail::get_field_metadata<type>(tag.value));
  });
}
} // namespace thrift
} // namespace apache
