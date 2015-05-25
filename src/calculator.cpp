#include "calculator.h"

namespace hpcos {

  void Calculator::calculate(const Input& input)
  {
    m_barrier->setNumberOfThreads(input.getThreads());

    for (unsigned i = 0; i < input.getThreads(); i++) {
      if (input.getMode() == 'f') {
        m_threads.push_back(std::thread(Calculator::compute_f, i,
                                        input.getThreads(),
                                        std::ref(*this)));
      } else {
        m_threads.push_back(std::thread(Calculator::compute_m, i,
                                        input.getThreads(),
                                        std::ref(*this)));
      }
    }

    std::for_each(m_threads.begin(), m_threads.end(),
                  std::mem_fn(&std::thread::join));
  }

  void calcf(unsigned id, unsigned n, char oi, Calculator& calc,
             const mpf_class& x)
  {
    char is_odd = id % 2;
    unsigned i = n;
    int iterations = 10;
    mpf_class fact2n {1.0};
    mpf_class lres {0.0};

    while (iterations--)
    {
     for (unsigned k = 2; k <= 2*i; k++)
       fact2n *= k;

     mpf_pow_ui(lres.get_mpf_t(), x.get_mpf_t(), 2*i);
     lres /= fact2n;

     if (is_odd) {
       calc.lock_result();
       calc.p_result += lres;
       calc.unlock_result();
     } else {
       calc.lock_result();
       calc.p_result += lres;
       calc.unlock_result();
     }

     calc.sync();

     i += n;
     if (oi)
       i ^= 0x1;
    }
  }

} // ns

