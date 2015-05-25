#include "calculator.h"
#include <iomanip>

namespace hpcos {

  void calcf(unsigned id, unsigned n, char oi, Calculator& calc,
             const mpf_class& x);


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
      if (input.getMode() == 'f') {
        m_threads.push_back(
            std::thread(calcf, i, threadsn, odd_incr,
                        std::ref(*this), input.getX()));
      } else {
        std::cout << "todo" << std::endl;
      }
    }

    std::for_each(m_threads.begin(), m_threads.end(),
                  std::mem_fn(&std::thread::join));

    std::ostringstream s;
    s << std::setprecision(100) <<  p_result;

    return s.str();
  }

  void calcf(unsigned id, unsigned n, char oi, Calculator& calc,
             const mpf_class& x)
  {
    char is_odd = id % 2;
    unsigned i = id;
    unsigned last_k = 2;
    unsigned k;
    int iterations = 100;
    mpf_class fact2n {1.0, 100000};
    mpf_class lres {0.0, 100000};

    while (iterations--)
    {
      fact2n = 1.0;
      for (k = 1; k <= 2*i; k++)
        fact2n *= k;

      std::cout << "i:" << i << std::endl;
      std::cout << last_k << "!: " << fact2n << std::endl;

      // lres = x^{2i}
      mpf_pow_ui(lres.get_mpf_t(), x.get_mpf_t(), 2*i);
      // lres = x^{2i}/(2n!)
      lres /= fact2n;

      if (is_odd) {
        calc.lock_result();
        calc.p_result -= lres;
        calc.unlock_result();
      } else {
        calc.lock_result();
        calc.p_result += lres;
        calc.unlock_result();
      }

      calc.sync();

      i += n;

      if (oi == 1)
        is_odd ^= 0x1;
    }
  }

} // ns

