---
id: terms
title: Terms
sidebar_label: Terms
---

## Terms preliminaries

Before we describe Hamiltonians, which are available, let's briefly describe terms, which are currently implemented in SOLIDstate.

The current version of the SOLIDstate has support only for  terms that can be described up to second rank tensor (matrix), which corresponds up to two-body terms.

<hr />

## Hop

### Fermions (spinless)

\\[
\sum_{ij}  \left(t_{ij} a^\dagger_i a_j + \mathrm{H.c.}\right)
\\]

**Standard label**: `t`

### Spins \\(\tfrac12\\)

\\[
\sum_{ij}  \left(J_{ij} S_i^+ S_j^- + \mathrm{H.c.}\right)
\\]

**Standard label**: TODO

<hr />

## Create Pair

### Fermions (spinless)

\\[
\sum_{ij}  \left(\Delta_{ij} a^\dagger_i a_j^\dagger + \mathrm{H.c.}\right)
\\]

**Standard label**: `delta`

<hr />

## One Body Interaction

### Fermions (spinless)

\\[
\sum_{i}  \mu_{i} \hat n_i
\\]

**Standard label**: `mu`

### Spins \\(\tfrac12\\)

\\[
\sum_{i}  h_{i} S_i^z
\\]

<hr />

## Two Body Interaction

### Fermions (spinless)

\\[
\sum_{ij}  V_{ij} \hat n_i \hat n_j
\\]

**Standard label**: `V`

### Spins \\(\tfrac12\\)

\\[
\sum_{ij}  J^z_{ij} S_i^z S_j^z
\\]