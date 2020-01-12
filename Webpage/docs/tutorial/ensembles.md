---
id: ensembles
title: Ensembles
sidebar_label: Ensembles
---

## Ensambles overview

The current version of the `SOLIDstate` supports the following statistical ensembles:

* `Canonical` ― ensemble with a fixed number of particles,
* `GrandCanonical` ― ensemble with all possible configuration with any number of particles in the system,
* `ParityGrandCanonical` ― similar to `GrandCanonical`, but with fixed parity of the particle number.

One of the `SOLIDstate` features is an easy switch between ensembles.
Moreover, one needs to design Hamiltonians only once.
The selection between the ensembles is done automatically.

In the previous example, we learned how to declare `qSystem`, an object of `QuantumSystem<T1, T2>` class.
To select ensemble use the following method:

```c++
qSystem.SelectEnsemble<Canonical>(L,L/2);
```

In the example the first number `L` type of `int` in the parameters of `SelectEnsemble` is system size ― the number of sites and the second parameter `L/2` is the number of particles \\(N\\) in the Ensemble.

General syntax for `SelectEnsamble` is the following:

```c++
SelectEnsemble<Ensemble>(L, options)
```

Below there are examples of usage of the ensembles with explanatory of ensemble options and ensemble descriptions.


## Canonical

The canonical ensemble has Hilbert Space for the selected number of particles:
\\[
\mathcal H_{\mathrm{canonical}} = \mathcal H_N =  \mathcal H^{\otimes N}
\\]

`Canonical` does have additional option ―  the number of particles in the Ensemble `N` (default is `N = 0`).
```c++
qSystem.SelectEnsemble<Canonical>(L,N);
```

## Grand Canonical
Grand Canonical ensemble assumes that system can be in Hilbert Space \\(\mathcal H_N \\) with any number of particles \\(N\\).
Total Hilbert space is equal to the direct sum of all \\(\mathcal H_N\\)
\\[
\mathcal H_{\textrm{grand canonical}} = \bigoplus_{N=0}^{L} \mathcal H_N = \mathcal H_0 \oplus \mathcal H_1 \oplus \cdots \oplus \mathcal H_L
\\]

`GrandCanonical` does not have any additional options
```c++
qSystem.SelectEnsemble<GrandCanonical>(L);
```

## Parity Grand Canonical

Parity Grand Canonical is similar to Grand Canonical Ensemble, but parity symmetry is implied.

One has two options for selecting system parity
* Even (default) parity:
\\[
\mathcal H_{\textrm{parity grand canonical}} = \bigoplus_{N=0}^{L/2} \mathcal H_{2N} 
\\]

* Odd parity:
\\[
\mathcal H_{\textrm{parity grand canonical}} = \bigoplus_{N=1}^{L/2} \mathcal H_{2N+1} 
\\]

`ParityGrandCanonical` does have additional option ― `parity` (default is even parity).
If parity is even/odd number (e.g. `0,2,4,...`/`1,3,5,...`) then selected parity is even/odd.
```c++
qSystem.SelectEnsemble<ParityGrandCanonical>(L,parity);
```

## Custom Ensemble

TODO