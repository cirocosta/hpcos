#include "calculator.h"

Calculator::Calculator()
    : m_Value(0)
{
}

Calculator::Calculator(int x)
    : m_Value(x)
{
}

void Calculator::accumulate(const int x) 
{
    m_Value += x;
}

