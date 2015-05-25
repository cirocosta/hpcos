#include "input.h"
#include "calculator.h"

#include "gtest/gtest.h"
#include <gmp.h>
#include <gmpxx.h>

#include <string>
#include <iostream>


class CalcTest : public ::testing::Test
{
protected:
  hpcos::Calculator calc;
  hpcos::Input inp0, inp1, inp_m_0;
protected:
  CalcTest()
  {
    mpf_set_default_prec(10000);
    const int argc = 5;
    const char* argv0[] = {
      "./src/main", "4", "f", "10", "1",
    };
    const char* argv1[] = {
      "./src/main", "4", "f", "110", "3.1415926553308963775634765625",
    };
    const char* argv_m_0[] = {
      "./src/main", "1", "m", "2", "1",
    };

    inp0 = hpcos::Input {argc, argv0};
    inp1 = hpcos::Input {argc, argv1};
    inp_m_0 = hpcos::Input {argc, argv_m_0};
  }

	virtual ~CalcTest() {}
	virtual void SetUp() {}
	virtual void TearDown() { }
};

TEST_F(CalcTest, Initialization) {
  mpf_class expected {0.0};

  EXPECT_EQ(calc.p_result, expected);
}

TEST_F(CalcTest, CalcF) {
  std::string cos1_10 {"0.5403023058681397174009366074429766037323104206179222276700972553811003947744717645179518560871830893"};

  EXPECT_EQ(calc.calculate(inp0), cos1_10);
}

TEST_F(CalcTest, CalcM) {
  std::string cos1_10 {"0.540302305"};

  EXPECT_EQ(calc.calculate(inp_m_0), cos1_10);
}

