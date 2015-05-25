# hpcos - EP2 Mac0328

Taking advantage of pthreads (for concurrency) and GMP (for precision) this lib aims to provide a high speed and very precise calculation of `cos(x)`.

## Usage

```sh
Usage:
        $ ./hpcos t (f|m) p x d?

Params:
t:      Number of threads to be used. If 0, uses
        t = #cores.

f|m:    Method for checking the precision.

p:      Precision. If in 'f' mode, for a value of
        110, stops when delta < 10exp(-110). If
        in 'm', stops when a thread calculates a
        term that is less than the given value.

x:      Value to be calculated (radians).

d:      Debug mode (optional).
```

### `f` mode

> stops when the absolute difference between two consecutive values is less than a precision `p` specified, that is, when the sum of all of the contributions is less than the specified.

### `m` mode

> stops when the absolute contribution of a term from a thread is less than `10^(-p)`

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

