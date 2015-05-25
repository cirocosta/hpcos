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

  void Calculator::compute_f(const unsigned id, const unsigned n,
                             Calculator& calc)
  {
    char is_odd = (id+1) % 2 ? 1 : 0;
    unsigned i = id;
    unsigned iterations = 10;

    while (iterations--){
      std::cout << "T_" << id << ": " << i << std::endl;
      calc.sync();
      i += n;
    }
  }

  void Calculator::compute_m(unsigned i, unsigned n, Calculator& calc)
  {
    std::cout << "TODO!" << std::endl;
  }
} // ns



/* void compute(mpf_t result, int n, mpf_t x) */
/* { */
/*   mpf_t fact2n, lres; */

/*   mpf_init_set_ui(fact2n, 1); */
/*   mpf_init_set_ui(lres, 0); */

/*   for (int i = 2; i <= 2*n; i++) */
/*     mpf_mul_ui(fact2n, fact2n, i); */

/*   mpf_pow_ui(lres, x, 2*n); */
/*   mpf_div(lres, lres, fact2n); */

/*   if (n%2) */
/*     mpf_sub(result, result, lres); */
/*   else */
/*     mpf_add(result, result, lres); */

/*   mpf_clear(lres); */
/*   mpf_clear(fact2n); */
/* } */
