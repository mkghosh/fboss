/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#include "fboss/agent/hw/test/dataplane_tests/HwLoadBalancerTests.h"

#include "fboss/agent/Platform.h"
#include "fboss/agent/hw/switch_asics/HwAsic.h"
#include "fboss/agent/hw/test/HwTestPacketUtils.h"

namespace facebook::fboss {

class HwLoadBalancerTestsV6InMplsSwap
    : public HwLoadBalancerTest<utility::HwMplsV6EcmpDataPlaneTestUtil> {
 public:
  bool skipTest() const override {
    return !getPlatform()->getAsic()->isSupported(HwAsic::Feature::MPLS_ECMP);
  }

 private:
  std::unique_ptr<utility::HwMplsV6EcmpDataPlaneTestUtil> getECMPHelper()
      override {
    return std::make_unique<utility::HwMplsV6EcmpDataPlaneTestUtil>(
        getHwSwitchEnsemble(),
        MPLSHdr::Label(utility::kHwTestMplsLabel, 0, false, 127),
        LabelForwardingAction::LabelForwardingType::SWAP);
  }
};

RUN_ALL_HW_LOAD_BALANCER_TEST_FRONT_PANEL(HwLoadBalancerTestsV6InMplsSwap)

} // namespace facebook::fboss
