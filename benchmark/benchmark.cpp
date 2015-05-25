#include "input.h"
#include "calculator.h"

#include <chrono>
#include <iostream>
#include <vector>
#include <utility>


using namespace std::chrono;
typedef duration<double, std::milli> timedelta;
std::vector<std::pair<std::string, timedelta>> times;

void show_times()
{
  for (auto &measured_time : times) {
    std::cout << measured_time.first << " : " << std::endl
              << measured_time.second.count()
              << std::endl;
  }
}

/* template<typename Lambda> */
/* void measure_time(hpcos::Input& inp, Lambda&& f) */
/* { */
/*   auto start = steady_clock::now(); */
/*   auto end = steady_clock::now(); */
/*   timedelta diff = end - start; */
/*   f(inp); */
/* } */

int main()
{
  hpcos::Calculator calc;
  const int argc = 5;
  const char* argv0[] = {
    "./src/main", "4", "f", "10", "1",
  };

  auto start = steady_clock::now();
  calc.calculate(hpcos::Input {argc, argv0});
  auto end = steady_clock::now();
  timedelta diff = end - start;
  times.push_back(std::make_pair("something", diff));

  show_times();

  return 0;
}
