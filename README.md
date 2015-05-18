### Simplified Temporal Resolution Prover (STRP)

STRP is an experimental theorem prover for Propositional Linear Time Temporal Logic based on the Simplified Temporal Resolution calculus.

### Publication and Benchmarks

Full details can be found in this [research paper](http://cgi.csc.liv.ac.uk/~rmw/cade13.pdf) and all the benchmarks used can be downloaded from [here](http://cgi.csc.liv.ac.uk/~rmw/benchmarks.zip).

### Source Installation

```sh
$ git clone https://github.com/richardw347/STRP_V2.git
$ cd STRP_V2 && mkdir build && cd build
$ cmake ../
$ make
$ sudo make install
```

## External Tools

STRP uses three external tools [CAMUS](http://sun.iwu.edu/~mliffito/camus/), [MTminer](https://forge.greyc.fr/projects/kdariane/wiki/Mtminer) and [SHD](http://research.nii.ac.jp/~uno/code/shd.html). We provide a repostory with all three tools:

```sh
$ git clone https://github.com/richardw347/STRP_EXT_TOOLS.git
$ cd STRP_EXT_TOOLS && make
$ sudo make install
```
## Example
Running STRP on this simple example can be done using the following command:
```sh
$ STRP_V2 -itf example.snf
```
This will generate the following output which indicates the problem is Unsatisfiable:
```sh
=====Inital Clauses=====
=====Universal Clauses=====
[-8, -4]
[-8, 3]
[-7, -4]
[-7, 2]
[1]
[2]
=====Step Clauses=====
[-5] => NEXT([6])
[-3] => NEXT([7])
[-2] => NEXT([8])
=====Sometime Problems=====
SOMETIME(4)
[] -> NEXT[]
==========End===========
Running step resolution search
mus count: 1

running loop search for: 4
loop candidate: [2] ∨ [3]
Cant term, searching again
loop candidate: [2] ∨ [3]
loop search termination successful adding new universal clauses
som: adding universal clause: [-3]
som: adding universal clause: [-2]
loop search successful

Applying initial termination rule
Unsatisfiable
step rule applied: 0
sometime rule applied: 1
universal clauses generated: 0
```
