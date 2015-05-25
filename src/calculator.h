#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <thread>
#include <vector>
#include <gmp.h>
#include <mutex>
#include <gmpxx.h>
#include <algorithm>

#include "input.h"
#include "utils/barrier.h"


namespace hpcos {

  class Calculator {
  private:
    std::vector<std::thread> m_threads;
    hpcos::utils::Barrier* m_barrier;
    bool m_kill;
    std::mutex m_result_mutex;
  public:
    mpf_class p_result;
  public:
    Calculator() :
      m_result(mpf_class {0.0}), m_barrier(new utils::Barrier()),
      m_kill(false)
    {}

    ~Calculator()
    {
      delete m_barrier;
    }

    inline bool shouldDie() { return m_kill; }
    inline void sync() { m_barrier->wait(); }
    inline void lock_result() { m_result_mutex.lock(); }
    inline void unlock_result() { m_result_mutex.unlock(); }

    void calculate(const Input& input);
  private:
    static void compute_m(unsigned i, unsigned n, Calculator& calc);
    static void compute_f(unsigned i, unsigned n, Calculator& calc);
  };

} // ns


#endif

