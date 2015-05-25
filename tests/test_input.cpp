#include "gtest/gtest.h"
#include "input.h"

#include <gmp.h>
#include <gmpxx.h>
#include <iostream>


class InputTest : public ::testing::Test
{
protected:
  hpcos::Input inputF;
  hpcos::Input inputM;
protected:
  InputTest()
  {
    const int argcF = 4;
    const int argcM = 4;

    const char* cliF[] = {
      "./src/main",
      "4",
      "110",
      "3.1415926553308963775634765625",
    };

    const char* cliM[] = {
      "./src/main",
      "4",
      "110",
      "3.1415926553308963775634765625",
    };

    inputF = hpcos::Input{argcF, cliF};
    inputM = hpcos::Input{argcM, cliM};
  }

	virtual ~InputTest() {}
	virtual void SetUp() {}
	virtual void TearDown() { }
};


TEST_F(InputTest, Threads) {
  EXPECT_EQ(4, inputF.getThreads());
  EXPECT_EQ(4, inputM.getThreads());
}


TEST_F(InputTest, Precision) {
  mpf_class expected_precision {10.0};
  mpf_pow_ui(expected_precision.get_mpf_t(),
             expected_precision.get_mpf_t(), 110);
  expected_precision = 1.0 / expected_precision;

  EXPECT_TRUE(mpf_cmp(expected_precision.get_mpf_t(),
              inputF.getPrecision().get_mpf_t()));
  EXPECT_TRUE(mpf_cmp(expected_precision.get_mpf_t(),
              inputM.getPrecision().get_mpf_t()));
}

TEST_F(InputTest, X) {
  mpf_class expected_x {"3.1415926553308963775634765625"};
  EXPECT_EQ(expected_x, inputF.getX());
}

