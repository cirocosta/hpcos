#include "input.h"

namespace hpcos {

Input::Input(const int& argc, const char** argv)
{
  m_precision.set_prec(100000);
  m_x.set_prec(100000);
  parse(argc, argv);
}

Input::Input()
{ }

void Input::parse_input(const int& argc, const char** argv)
{
  m_precision.set_prec(100000);
  m_x.set_prec(100000);

  parse(argc, argv);
}

void Input::print_usage()
{
  cout << "Usage:" << endl
       << "\t $ ./hpcos  t (f|m) p x d?" << endl
       << endl
       << "Params:" << endl
       << "t:\tNumber of threads to be used if 0, uses" << endl
       << "\t t = number of cores." << endl
       << endl
       << "sv:\t Accepted error for a thread in an iteration" << endl
       << endl
       << "x:\t value to be calculated (radians)" << endl
       << endl
       << "d:\t debug mode (optional" << endl
       << endl;
}

unsigned Input::parse_ul(const char* c)
{
  int ul;

  try {
    ul = std::stoul(c);
  } catch (std::exception const &e) {
    cerr << "InputError: " << e.what() << endl;
    exit(1);
  }

  return ul;
}

int Input::parse_int(const char* c)
{
  int i = -1;

  try {
    i = std::stoi(c);
  } catch (std::exception const &e) {
    cerr << "InputError: " << e.what() << endl;
    exit(1);
  }

  return i;
}

mpf_class Input::parse_mpf(const char* number)
{
  mpf_class n;

  try {
    n.set_str(number, 10);
  } catch (std::invalid_argument e) {
    std::cerr << "InputError:" << std::endl
              << "The string supplied for 'x' is not valid" << std::endl
              << "Exception raised:" << std::endl
              << e.what() << std::endl;
    exit(1);
  }

  return n;
}

void Input::parse(const int &argc, const char** argv)
{
  if (argc < 4) {
    print_usage();
    std::cerr << "Minimum number of arguments not provided."
              << std::endl;
    std::exit(1);
  }

  m_threads = parse_ul(argv[1]);
  if (!m_threads) {
    unsigned concurrentThreads = std::thread::hardware_concurrency();

    if (!concurrentThreads) {
      cerr << "Couldn't find number of concurrent threads." << endl
           << "Maybe there's a misconfig in your computer." << endl
           << "Please specify the number of threads." << endl;
      std::exit(1);
    }

    m_threads = concurrentThreads;
  }

  // precision
  int prec = parse_int(argv[2]);
  mpf_class ten (10);

  mpf_pow_ui(m_precision.get_mpf_t(), ten.get_mpf_t(), prec);
  m_precision  = 1/m_precision;

  // x
  m_x = parse_mpf(argv[3]);
}

} // ns

