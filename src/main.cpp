#include <iomanip>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>
#include <gmp.h>

#include "input.h"

using namespace hpcos;

//TODO 'usage' print and settings helper

//TODO get cpu cores

//TODO implement butterfly barrier as well as
//     other types to compare

//TODO learn how to measure execution time of
//     different parts of out code with a great
//     precision.


void compute(mpf_t result, int n, mpf_t x)
{
  mpf_t fact2n, lres;

  mpf_init_set_ui(fact2n, 1);
  mpf_init_set_ui(lres, 0);

  for (int i = 2; i <= 2*n; i++)
    mpf_mul_ui(fact2n, fact2n, i);

  mpf_pow_ui(lres, x, 2*n);
  mpf_div(lres, lres, fact2n);

  if (n%2)
    mpf_sub(result, result, lres);
  else
    mpf_add(result, result, lres);

  mpf_clear(lres);
  mpf_clear(fact2n);
}

int main(const int argc, const char** argv) {
  Input input (argc, argv);


  std::cout << "output:" << endl
            << input << std::endl;


  mpf_set_default_prec(1000);
  mpf_t result, x;

  mpf_init_set_ui(result, 0);
  mpf_init_set_ui(x, 1);

  for (int i = 0; i < 1000; i++)
    compute(result, i, x);

  mpf_out_str(stdout, 10, 0, result);

  mpf_clear(result);
  mpf_clear(x);

  return 0;
}
