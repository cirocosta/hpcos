#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "input.h"
#include "utils/barrier.h"

#include <gmp.h>
#include <gmpxx.h>

#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>


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
    Calculator();
    ~Calculator() { delete m_barrier; }

    inline bool shouldDie() { return m_kill; }
    inline void sync() { m_barrier->wait(); }
    inline void syncf()
    {

    }

    inline void lock_result() { m_result_mutex.lock(); }
    inline void unlock_result() { m_result_mutex.unlock(); }
    inline void kill() { m_kill = true; }

    std::string calculate(const Input& input);
  private:
    static void compute_m(unsigned i, unsigned n, Calculator& calc);
    static void compute_f(unsigned i, unsigned n, Calculator& calc);
  };

} // ns


#endif

