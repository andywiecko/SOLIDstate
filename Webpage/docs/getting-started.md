---
id: getting-started
title: Getting started
sidebar_label: Install
---

## Install requirements

SOLIDstate depends on the [Armadillo](http://arma.sourceforge.net/) library.
Before installing SOLIDstate please follow the instruction for Armadillo installation.
Before installing Armadillo, it is recommended to install (at least) the following libraries: 
[LAPACK](http://www.netlib.org/lapack/),
[ARPACK](https://www.caam.rice.edu/software/ARPACK/),
[BLAS](http://www.netlib.org/blas/),
[OPENBLAS](https://www.openblas.net/) (**<span style="color:red">highly recommended!</span>**).
When the installation of the selected libraries is completed, please install Armadillo.

## Install SOLIDstate

### Download the source

SOLIDstate can be cloned from [GitHub](https://github.com/andywiecko/SOLIDstate):

```bash
git clone https://github.com/andywiecko/SOLIDstate
```

### Compiling the source

Before using the SOLIDstate, a user has to compile the source code.
`make` program is required for compiling the source.
Go into the folder, where `SOLIDstate` has been extracted and type:

```bash
make
```

**Caveat:** if many cores are available use `-j` option for quicker building. E.g. if the user has 8 cores available:

```bash
make -j8
```

### Installing the source

After successful `make`, one should install the library by using the following command:

```bash
make install
```

(User probably should run it with a `sudo`: `sudo make install`)
