#include <thread>
#include <cstdio>
#include <vector>
#include <algorithm>

#include "utils/barrier.h"

using namespace hpcos;
utils::Barrier barrier {};

void busy_func(unsigned thread_id)
{
  int i = 10;

  while (i--) {
    printf("T%d came!\n", thread_id);
    barrier.enter();
    printf("\tT%d INSIDE!\n", thread_id);
    barrier.leave();
  }
}

int main() {

  std::vector<std::thread> threads;

  for (int i = 0; i < 3; i++)
    threads.push_back(std::thread(busy_func, i));
  barrier.setNumberOfThreads(threads.size());

  std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
    t.join();
  });

  printf("Exiting main\n");

  return 0;
}
