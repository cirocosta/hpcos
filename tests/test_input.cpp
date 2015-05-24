#include <iostream>
#include "gtest/gtest.h"
#include "input.h"

class InputTest : public ::testing::Test
{
protected:
  hpcos::Input inputF;
  hpcos::Input inputM;
protected:
  InputTest()
  {
    const int argcF = 5;
    const int argcM = 5;

    const char* cliF[] = {
      "./src/main",
      "4",
      "f",
      "10",
      "1",
    };

    const char* cliM[] = {
      "./src/main",
      "4",
      "m",
      "10",
      "1",
    };

    inputF = hpcos::Input{argcF, cliF};
    inputM = hpcos::Input{argcM, cliM};
  }

	virtual ~InputTest() {}
	virtual void SetUp() {}
	virtual void TearDown() { }
};


TEST_F(InputTest, Initialization) {
    EXPECT_EQ(4, inputF.getThreads());
    EXPECT_EQ(4, inputM.getThreads());
}

