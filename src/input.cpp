#include "input.h"

namespace hpcos {

Input::Input(const int& argc, const char** argv)
  : m_debug(false)
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
       << "f|m:\t Method for checking the precision." << endl
       << endl
       << "p:\t Precision" << endl
       << endl
       << "x:\t value to be calculated" << endl
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
  }

  return ul;
}

int Input::parse_int(const char* c)
{
  int i;
  try {
    i = std::stoi(c);
  } catch (std::exception const &e) {
    cerr << "InputError: " << e.what() << endl;
  }

  return i;
}

mpf_class Input::parse_mpf(const char* number)
{
  mpf_class n;

  try {
    n.set_str(number, 10);
  } catch (std::invalid_argument e) {
    std::cerr << "The string supplied for 'x' is not valid" << std::endl
              << "Exception raised:" << std::endl
              << e.what() << std::endl;
  }

  return n;
}

void Input::parse(const int &argc, const char** argv)
{
  if (argc < 5) {
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

  // mode
  if (*argv[2] == 'f')
    m_mode = 'f';
  else if (*argv[2] == 'm')
    m_mode = 'm';
  else {
    print_usage();
    cerr << "Not a valid mode. Must be 'f' or 'm'" << endl;
    std::exit(1);
  }

  // precision
  int prec = parse_int(argv[3]);
  mpf_class ten (10);

  mpf_pow_ui(m_precision.get_mpf_t(), ten.get_mpf_t(), prec);
  m_precision  = 1/m_precision;

  // x
  m_x = parse_mpf(argv[4]);

  // debug
  if (argc > 5 && *argv[5] == 'd')
    m_debug = true;
}

} // ns

