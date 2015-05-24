#include <thread>
#include <cstdio>
#include <vector>
#include <algorithm>

void busy_func(unsigned thread_id)
{
  printf("T%d came!\n", thread_id);
}

int main() {
  /* utils::Barrier barrier {}; */

  std::vector<std::thread> threads;

  for (int i = 0; i < 10; i++)
    threads.push_back(std::thread(busy_func, i));

  std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
    t.join();
  });

  printf("Exiting main\n");

  return 0;
}
