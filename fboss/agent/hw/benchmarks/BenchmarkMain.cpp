/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#include <folly/Benchmark.h>
#include <folly/init/Init.h>
namespace facebook {
namespace fboss {
// Each benchmark must implement this to do preliminary
// setup (primarily bringing up switch) before beginning
// benchmark operations
void setupBenchmark();
} // namespace fboss
} // namespace facebook

int main(int argc, char* argv[]) {
  folly::init(&argc, &argv, true);
  facebook::fboss::setupBenchmark();
  folly::runBenchmarks();
  return 0;
}