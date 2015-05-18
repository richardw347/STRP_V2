### Simplified Temporal Resolution Prover (STRP)

STRP is an experimental theorem prover for Propositional Linear Time Temporal Logic based on the Simplified Temporal Resolution calculus.

### Source Installation

```sh
$ git clone https://github.com/richardw347/STRP_V2.git
$ cd STRP_V2 && mkdir build && cd build
$ cmake ../
$ make
```

## Installation Instructions

STRP uses three external tools CAMUS, MTminer and SHD. We provide a repostory with all three tools:

```sh
$ git clone https://github.com/richardw347/STRP_EXT_TOOLS.git
$ cd STRP_EXT_TOOLS && make
```
Finally to simplify setup STRP assumes the binaries located in a directory in your PATH, so either copy each binary (camus_mcs, camus_mus, mtminer, shd) to an appropriate directory (e.g. /bin) or add the relevant directories to the path.
