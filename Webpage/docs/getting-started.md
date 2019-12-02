---
id: getting-started
title: Getting started
sidebar_label: Install
---

## Install requirements

SOLIDstate depends on [Armadillo](http://arma.sourceforge.net/) library.
Before installing SOLIDstate please follow the instruction for Armadillo instalation.
Before installing Armadillo, it is recomended to install (at least) the following libraries: 
[LAPACK](http://www.netlib.org/lapack/),
[ARPACK](https://www.caam.rice.edu/software/ARPACK/),
[BLAS](http://www.netlib.org/blas/),
[OPENBLAS](https://www.openblas.net/) (**<span style="color:red">highly recomended!</span>**).
When instalation of the selected libraries is completed, please install Armadillo.

## Install SOLIDstate

### Download the source
SOLIDstate can be download from [sourceforge.net](https://sourceforge.net/) or it can be cloned from [GitHub](https://github.com/andywiecko/SOLIDstate):
```bash
git clone https://github.com/andywiecko/SOLIDstate
```

### Compiling the source

Before using the SOLIDstate, user has to compile the source code.
`make` program is required for compiling the source. 
Go into folder, where `SOLIDstate` has been extracted and type:
```bash
make
```

**Caveat:** if many cores are avaliable use `-j` option for quickier building. E.g. if user has 8 cores avaliable:
```bash
make -j8
```

### Installing the source

After succesful `make`, one should install the library by using the following command:
```bash
make install
```
(User probably should run it with a `sudo`: `sudo make install`)
