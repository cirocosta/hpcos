#include "barrier.h"

namespace hpcos { namespace utils {

    Barrier::Barrier(const unsigned int n)
      : m_nthreads(n), m_counter(0),
        m_t1(new Semaphore(0)), m_t2(new Semaphore(0))
    {}

    Barrier::~Barrier()
    {
      delete m_t1;
      delete m_t2;
    }

    // TODO fix this.
    void Barrier::setNumberOfThreads(const unsigned int n)
    {
      m_nthreads = n;
    }

    void Barrier::enter()
    {
      m_mutex.lock();
      m_counter++;
      if (m_counter == m_nthreads) {
        m_t1->signal(m_nthreads);
      }
      m_mutex.unlock();
      m_t1->wait();
    }

    void Barrier::leave()
    {
      m_mutex.lock();
      m_counter--;
      if (m_counter == 0) {
        m_t2->signal(m_nthreads);
      }
      m_mutex.unlock();
      m_t2->wait();
    }

    void Barrier::wait()
    {
      enter();
      leave();
    }

}}
