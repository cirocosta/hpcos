#ifndef SEMPAHORE_H
#define SEMPAHORE_H

#include <thread>
#include <condition_variable>
#include <mutex>

namespace hpcos { namespace utils {

  class Semaphore
  {
  public:
    std::mutex m_mutex;
    std::condition_variable m_cond;
    unsigned int m_counter;
  public:
    Semaphore(const unsigned int initial_counter);
    ~Semaphore();

    void wait();
    void signal();
    void signal(unsigned n);
    void signal_all();
  };

}} //ns

#endif
