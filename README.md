# hpcos

Taking advantage of pthreads (for concurrency) and GMP (for precision) this lib aims to provide a high speed and very precise calculation of `cos(x)`.

## Usage

```sh
Usage:
        $ ./hpcos t (f|m) p x d?

Params:
t:      Number of threads to be used. If 0, uses
        t = #cores (recommended)

e:      Minimum contribution that an iteration
        might provide per thread. Uses 10^{-e}
        for the comparison.

x:      Value to be calculated (radians).
```

## Install

Basic:

```sh
$ mkdir build && cd build
$ cmake ..
$ make
$ ./src/main (args)
```

Tests included:

```sh
$ mkdir build && cd build
$ cmake -Dtest=ON ..
$ make
$ make test
$ ./src/main (args)
```

ps.: If you wish to debug and etc i recommend switching to clang++ when compiling. To do so:

```sh
export CXX=/usr/bin/clang++
```

before running `cmake -Dtest=ON ..`.

For debug builds don't forge to add `-DCMAKE_BUILD_TYPE=Debug`.
Realease builds with `DCMAKE_BUILD_TYPE=Release`.

## LICENSE

GPLv3

See `LICENSE` file.

