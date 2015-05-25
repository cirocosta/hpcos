# hpcos

> high precision and fast cosine calculator

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
```

Tests included:

```sh
$ mkdir build && cd build
$ cmake -Dtest=ON ..
$ make
$ make test
```

ps.: If you wish to debug and etc i recommend switching to clang++ when compiling. To do so:

```sh
export CXX=/usr/bin/clang++
```

before running `cmake -Dtest=ON ..`.

For debug builds don't forge to add `-DCMAKE_BUILD_TYPE=Debug`.
Realease builds with `DCMAKE_BUILD_TYPE=Release`.


### Comparison and verifying if right

Firstly it relies on calculating a result for a lower precision and then seeing if it is contained in a solution for a higher precision.

After that, cross-comparison with [mpmath library](http://mpmath.org/) for Python (you can check the test cases inside `tests/`).

### Times

//TODO

Hardware:
- machine 1
  - Intel® Core™ i5-460M Processor (3M Cache, 2.53 GHz, 2 cores) 1st gen
  - 3072 GB Ram
  - HDD

- machine 2
  - Intel® Core™ i5-4210U Processor (3M Cache, 1.7 Ghz, 2 cores) 4th gen
  - 8192 GB Ram
  - SSD

## Hacking

The folder structure ir pretty clear, but in case you're not familiar:

`lib/`: included libraries. Here is where GTest code lives, e.g.
`src/`: contains source files
`tests/`: tests for the source files

## LICENSE

GPLv3

See `LICENSE` file.

