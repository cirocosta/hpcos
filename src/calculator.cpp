#include "calculator.h"

namespace hpcos {

  Calculator::Calculator() :
    m_barrier(new utils::Barrier()), m_kill(false)
  {
    p_result.set_prec_raw(10000);
  }

  std::string Calculator::calculate(const Input& input)
  {
    const unsigned threadsn = input.getThreads();
    const char odd_incr = threadsn % 2;
    m_barrier->setNumberOfThreads(threadsn);

    for (unsigned i = 0; i < threadsn; i++) {
      m_threads.push_back(
          std::thread(calcm, i, threadsn, odd_incr,
                      std::ref(*this), input.getX(),
                      input.getPrecision()));
    }

    std::for_each(m_threads.begin(), m_threads.end(),
                  std::mem_fn(&std::thread::join));

    std::ostringstream s;
    s << std::setprecision(100) <<  p_result;

    return s.str();
  }

  /**
   * Stops when the absolute contribution of a
   * term from a thread is less than the
   * precision specified during initialization
   * (CLI)
   */
  void Calculator::calcm(unsigned id, unsigned n, char oi,
                         Calculator& calc, const mpf_class& x,
                         const mpf_class& prec)
  {
    char is_odd = id % 2;
    unsigned i = id;
    unsigned k;
    mpf_class fact2n {1.0, 100000};
    mpf_class lres {0.0, 100000};
    mpf_class my_contrib {0.0, 100000};

    while (!calc.shouldDie())
    {
      fact2n = 1.0;
      for (k = 1; k <= 2*i; k++)
        fact2n *= k;

      mpf_pow_ui(lres.get_mpf_t(), x.get_mpf_t(), 2*i);
      lres /= fact2n;

      if (is_odd)
        my_contrib -= lres;
      else
        my_contrib += lres;

      if (lres < prec)
        calc.kill();
      calc.sync();

      i += n;
      if (oi == 1)
        is_odd ^= 0x1;
    }

    calc.lock_result();
    calc.p_result += my_contrib;
    calc.unlock_result();
  }

} // ns

