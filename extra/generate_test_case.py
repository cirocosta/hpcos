from __future__ import print_function
from sys import argv
from mpmath import *


def usage():
    print("Usage: ./generate_test_case (tests)")
    print("\ttests: \tnumber of tests to return")


def main():
    N = 20 if len(argv) < 2 else N

    for i in xrange(1, N):
        precision = 10 * i
        mp.dps = precision
        print(precision, ",", mp.cos(1))


if __name__ == '__main__':
    main()
else:
    print("You shouldn't be importing this.")
    exit(1)

