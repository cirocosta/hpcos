#ifndef INPUT_H
#define INPUT_H

#include <gmp.h>
#include <gmpxx.h>

#include <iostream>
#include <string>
#include <thread>


namespace hpcos {

  using std::cout;
  using std::cerr;
  using std::endl;

  /**
   * Handles input of the form:
   * $ ./main threads sv x
   */
  class Input
  {
  private:
    unsigned m_threads;
    mpf_class m_precision;
    mpf_class m_x;
  public:
    Input (const int& argc, const char** argv);
    Input ();

    void parse_input(const int& argc, const char** argv);

    inline mpf_class getPrecision() const { return m_precision; }
    inline unsigned getThreads() const { return m_threads; }
    inline mpf_class getX() const { return m_x; }

    friend std::ostream& operator<<(std::ostream& os, const Input& in)
    {
      os << "threads: " << in.m_threads << endl
         << "precision: " << in.m_precision << endl
         << "x: " << in.m_x << endl;

      return os;
    }
  private:
    static void print_usage();
    static int parse_int(const char* c);
    static unsigned parse_ul(const char* c);
    static mpf_class parse_mpf(const char* n);

    void parse(const int& argc, const char** argv);
  };

} //ns

#endif

