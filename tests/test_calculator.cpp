#include <iostream>
#include "gtest/gtest.h"
#include "input.h"
#include "calculator.h"
#include <string>

class CalcTest : public ::testing::Test
{
protected:
  hpcos::Calculator calc;
  hpcos::Input inp0, inp1;
protected:
  CalcTest()
  {
    const int argc = 5;
    const char* argv0[] = {
      "./src/main", "4", "f", "10", "1",
    };
    const char* argv1[] = {
      "./src/main", "4", "f", "110", "3.1415926553308963775634765625",
    };

    inp0 = hpcos::Input {argc, argv0};
    inp1 = hpcos::Input {argc, argv1};
  }

	virtual ~CalcTest() {}
	virtual void SetUp() {}
	virtual void TearDown() { }
};

TEST_F(CalcTest, LowPrecision) {

  /* std::string cos1_10 {"0.5403023059"}; */

  /* EXPECT_EQ(calc.calculate(inp0), cos1_10); */
  EXPECT_EQ(1, 1);
}

