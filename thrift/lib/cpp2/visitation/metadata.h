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

#include <folly/Indestructible.h>
#include <thrift/lib/thrift/gen-cpp2/metadata_types.h>

namespace apache {
namespace thrift {
namespace detail {

/**
 * Get ThriftMetadata of given thrift structure. If no_metadata option is
 * enabled, return empty data.
 *
 * @tparam T thrift structure
 *
 * @return ThriftStruct (https://git.io/JJQpW)
 */
template <class T>
const auto& get_struct_metadata() {
  static const folly::Indestructible<metadata::ThriftStruct> data = [] {
    metadata::ThriftMetadata metadata;
    md::StructMetadata<T>::gen(metadata);
    if (metadata.structs.empty()) {
      // if metadata is disabled
      return metadata::ThriftStruct{};
    }

    return std::move(metadata.structs.begin()->second);
  }();
  return *data;
}

/**
 * Get ThriftMetadata of given thrift structure. If no_metadata option is
 * enabled, return empty data.
 *
 * @tparam T thrift structure
 * @param idx field index
 *
 * @return ThriftField (https://git.io/JJQpY)
 */
template <class T>
const auto& get_field_metadata(size_t idx) {
  static const folly::Indestructible<metadata::ThriftField> empty;
  const auto& fields = get_struct_metadata<T>().fields;
  return idx < fields.size() ? fields[idx] : *empty;
}

} // namespace detail
} // namespace thrift
} // namespace apache
