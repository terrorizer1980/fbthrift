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

#include <thrift/lib/cpp2/async/tests/util/gen-cpp2/TestStreamService.h>

namespace testutil {
namespace testservice {

class TestStreamService : public TestStreamServiceSvIf {
 public:
  apache::thrift::ServerStream<int32_t> range(int32_t from, int32_t to)
      override;

  apache::thrift::ServerStream<int32_t> rangeThrow(int32_t from, int32_t to)
      override;

  apache::thrift::ServerStream<int32_t> rangeThrowUDE(int32_t from, int32_t to)
      override;
};

} // namespace testservice
} // namespace testutil