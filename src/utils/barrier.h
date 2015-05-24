#ifndef BARRIER_H
#define BARRIER_H

#include <mutex>
#include "semaphore.h"
//TODO remove this
#include <cstdio>

namespace hpcos { namespace utils {

  class Barrier
  {
  private:
    unsigned int m_nthreads;
    unsigned int m_counter;
    Semaphore* m_t1;
    Semaphore* m_t2;
    std::mutex m_mutex;
  public:
    Barrier(const unsigned int n = 0);

    ~Barrier();

    void setNumberOfThreads(const unsigned int n);
    void enter();
    void leave();
    void wait();
  };

}} //ns

#endif
