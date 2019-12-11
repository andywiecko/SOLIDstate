---
id: ensembles
title: Ensembles
sidebar_label: Ensembles
---

## Ensambles overview

Current version of the `SOLIDstate` supports the following statistical ensembles:
* `Canonical` ― enesemble with fixed number of particles,
* `GrandCanonical` ― ensemble with all possible configuration with any number of particles in the system,
* `ParityGrandCanonical` ― similar to `GrandCanonical`, but with fixed parity of the particle number.

One of the `SOLIDstate` feature is easy switch between ensembles, without any pain.
Moreover, one needs to design Hamiltonians only once. 
Selection between the ensembles is done automatically.

In the previous example, we learned how to declare `qSystem`, an object of `QuantumSystem<T1, T2>` class.
To select enesemble use the following method:
```c++
qSystem.SelectEnsemble<Canonical>(L,L/2);
```
In the example the first number `L` type of `int` in the parameters of `SelectEnsemble` is system size ― number of sites, and the second parameter `L/2` is number of particles \\(N\\) in the Ensemble.

General syntax for `SelectEnsamble` is the following:
```c++
SelectEnsemble<Ensemble>(L, options)
```
Below there are examples of usage of the ensemles with explanatory of ensemble options and ensemble descriptions.


## Canonical

Canonical ensmeble
\\[
\mathcal H = \mathcal H_N
\\]


## Grand Canonical
Grand Canonical ensemble assumes that system can be in Hilbert Space \\(\mathcal H_N \\) with any number of particles \\(N\\).
Total Hilbert space is equal to direct sum of all \\(\mathcal H_N\\)
\\[
\mathcal H = \bigoplus_{N=0}^{L} \mathcal H_N = \mathcal H_0 \oplus \mathcal H_1 \dots \oplus \dots \mathcal H_L
\\]

`GrandCanonical` does not have any additional options
```c++
qSystem.SelectEnsemble<GrandCanonical>(L);
```

## Parity Grand Canonical

Parity Grand Canonical is similar to Grand Canonical Ensemble, but parity symmetry is implied.

One has to options for selecting system parity
* Even parity:
\\[
\mathcal H = \bigoplus_{N=0}^{L/2} \mathcal H_{2N} 
\\]

* Odd parity:
\\[
\mathcal H = \bigoplus_{N=1}^{L/2} \mathcal H_{2N+1} 
\\]

`ParityGrandCanonical` does have additional option ― `parity` 
```c++
qSystem.SelectEnsemble<GrandCanonical>(L,parity);
```