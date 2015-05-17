# hpcos

> high precision and fast cosine calculator

Taking advantage of pthreads (for concurrency) and GMP (for precision) this lib aims to provide a high speed and very precise calculation of `cos(x)`.

##

```sh
Usage:
        $ ./hpcos i (f|m) p x d?

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

## Install

Basic:

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Tests included:

```sh
$ mkdir build
$ cd build
$ cmake -Dtest=ON ..
$ make
$ make test
```

Stop criteria: 
- error < f
- when a thread calculates a term less than a M given to the program


### ok, but from where the results came from?

Firstly it relies on calculating a result for a lower precision and then seeing if it is contained in a solution for a higher precision. 

After that, cross-comparison with [mpmath library](http://mpmath.org/) for Python (you can check the test cases inside `tests/`).

## Hacking

The folder structure ir pretty clear, but in case you're not familiar:

`lib/`: included libraries. Here is where GTest code lives, e.g.
`src/`: contains source files
`tests/`: tests for the source files

## LICENSE

GPLv3

See `./LICENSE` file.
