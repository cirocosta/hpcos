#include <iostream>
#include "gtest/gtest.h"
#include "calculator.h"


// The fixture for testing class Project1. From google test primer.
class CalculatorTest : public ::testing::Test {
protected:
	CalculatorTest() {
        c1 = Calculator();
    }

	virtual ~CalculatorTest() { }

	virtual void SetUp() {
	}

	virtual void TearDown() { }

    Calculator c1; 
};

TEST_F(CalculatorTest, Initialization) {
    EXPECT_EQ(0, c1.getInternalValue());
}

