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

    Semaphore(const unsigned int initial_counter)
      : m_counter(initial_counter)
    {}

    ~Semaphore()
    {}

    // <await (s > 0) s-->
    void wait()
    {
      std::unique_lock<std::mutex> lock (m_mutex);
      m_cond.wait(lock, [this] { return m_counter > 0; });
      m_counter--;
    }

    // <s++>
    void signal()
    {
      std::lock_guard<std::mutex> lock (m_mutex);
      m_counter++;
      m_cond.notify_one();
    }

    void signal_all()
    {
      std::lock_guard<std::mutex> lock (m_mutex);
      m_counter++;
      m_cond.notify_all();
    }
  };

}} //ns
