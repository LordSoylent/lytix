// Copyright (c) 2011-2013 The Bitcoin Core developers
// Copyright (c) 2017 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 /*p259201*/ pgenesis = uint256("0x0000028b94db22c97211ba15866bc2c9bc0daa7e9ac410a6c9660d8be19915c7");
    uint256 /*p623933*/ pblock10 = uint256("0x");
    BOOST_CHECK(Checkpoints::CheckBlock(/*259201*/0, /*p259201*/ pgenesis));
    // BOOST_CHECK(Checkpoints::CheckBlock(/*623933*/10, /*p623933*/ pblock10));


    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(/*259201*/0, /*p623933*/ pblock10));
    // BOOST_CHECK(!Checkpoints::CheckBlock(/*623933*/10, /*p259201*/ pgenesis));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(/*259201*/0+1, /*p623933*/ pblock10));
    BOOST_CHECK(Checkpoints::CheckBlock(/*623933*/10+1, /*p259201*/ pgenesis));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= /*623933*/0); // Use last recorded checkpoint?
}

BOOST_AUTO_TEST_SUITE_END()
