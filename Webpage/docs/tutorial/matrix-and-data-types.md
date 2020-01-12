---
id: matrix-and-data-types
title: Matrix and data types
sidebar_label: Matrix and data types
---

Current in SOLIDstate there are available two data containers types for storing matrix elements:

* `arma::Mat` ― dense matrix format,
* `arma::SpMat` ― sparse matrix format.

For each data container, one can set which type of numbers are stored:

* `double` real numbers with double precision,
* `arma::cx_double` (typedef for `std::complex<double>`) complex numbers with double precision.

Since `SOLIDstate` is a template library, switch between those data containers and data type is done by the templates.
For most of the object, one can set it as in the following example

```c++
QuantumSystem<arma::SpMat, double> qSystem;
```

Such command declares `qSystem` object of class `QuantumSystem<T1, T2>` with data container set to sparse matrix filled with `double` numbers.
`QuatnumSystem<T1, T2>` is one of the most important classes in this library.
`QuantumSystem<T1, T2>` is used for storing information about the system, its Hamiltonian, matrix elements, statistical ensemble, etc.
More detail description will be presented in the next Turorial pages.
