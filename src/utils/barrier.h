#ifndef BARRIER_H
#define BARRIER_H

#include <mutex>
#include "semaphore.h"

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
    Barrier(const unsigned int n = 0)
      : m_nthreads(n), m_counter(0),
        m_t1(new Semaphore(0)), m_t2(new Semaphore(0))
    {}

    ~Barrier()
    {
      delete m_t1;
      delete m_t2;
    }

    // TODO fix this.
    inline void setNumberOfThreads(const unsigned int n)
    {
      m_nthreads = n;
    }

    inline void enter()
    {
      m_mutex.lock();
      m_counter++;
      if (m_counter == m_nthreads - 1)
        m_t1->signal_all();
      m_mutex.unlock();
      m_t1->wait();
    }

    inline void leave()
    {
      m_mutex.lock();
      m_counter--;
      if (m_counter == 0)
        m_t2->signal_all();
      m_mutex.unlock();
      m_t2->wait();
    }

    inline void wait()
    {
      enter();
      leave();
    }

  };

}} //ns

#endif
