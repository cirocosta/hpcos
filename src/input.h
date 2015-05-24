#ifndef INPUT_H
#define INPUT_H

#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>

namespace hpcos {

  using std::cout;
  using std::cerr;
  using std::endl;

  /**
   * Handles input
   */
  class Input
  {
  private:
    unsigned m_threads;
    char m_mode;
    mpf_class m_precision;
    mpf_class m_x;
    bool m_debug;
  public:
    Input (const int& argc, const char** argv);

    inline mpf_class getPrecision() const { return m_precision; }
    inline int getThreads() const { return m_threads; }
    inline char getMode() const { return m_mode; }
    inline mpf_class getX() const { return m_x; }
    inline float getDebug() const { return m_debug; }

    friend std::ostream& operator<<(std::ostream& os, const Input& in)
    {
      os << "threads: " << in.m_threads << endl
         << "mode: " << in.m_mode << endl
         << "precision: " << in.m_precision << endl
         << "x: " << in.m_x << endl
         << "debug: " << in.m_debug;

      return os;
    }
  private:
    static void print_usage();
    static int parse_int(const char* c);
    static mpf_class parse_mpf(const char* n);

    void parse(const int& argc, const char** argv);
  };

} //ns

#endif

