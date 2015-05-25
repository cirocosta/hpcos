#include "calculator.h"
#include "input.h"

int main(const int argc, const char *argv[])
{
  hpcos::Input inp(argc, argv);
  hpcos::Calculator calc;

  calc.calculate(inp);

  return 0;
}

