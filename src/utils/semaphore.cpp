#include "semaphore.h"

namespace hpcos { namespace utils {

    Semaphore::Semaphore(const unsigned int initial_counter)
      : m_counter(initial_counter)
    {}

    Semaphore::~Semaphore()
    {}

    void Semaphore::wait()
    {
      std::unique_lock<std::mutex> lock (m_mutex);
      m_cond.wait(lock, [this] { return m_counter > 0; });
      m_counter--;
    }

    // <s++>
    void Semaphore::signal()
    {
      std::lock_guard<std::mutex> lock (m_mutex);
      m_counter++;
      m_cond.notify_one();
    }

    void Semaphore::signal(unsigned n)
    {
      while (n--)
        signal();
    }

    void Semaphore::signal_all()
    {
      std::lock_guard<std::mutex> lock (m_mutex);
      m_counter++;
      m_cond.notify_all();
    }

}}
