---
id: example-program
title: Running an example program
sidebar_label: Example program
---

```c++
#include<armadillo>
#include<SOLIDstate>

using namespace solid;
int main()
{
    int L = 12; // system size
	QuantumSystem<arma::Mat, double> quantumSystem;
    quantumSystem.SelectEnsemble<GrandCanonical>(L);
    // filling the parameters
    vec mu;
	mu.set_size(L);
	mu.fill(1);
	Parameters<double> param;
	param['M'] = mu;
	quantumSystem.parameters = param;
    quantumSystem.SelectHamiltonian<KitaevHamiltonian>();
	quantumSystem.Fill(); // fill matrix elements

    return 0;
}
```