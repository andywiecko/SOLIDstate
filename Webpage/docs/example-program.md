---
id: example-program
title: Running an example program
sidebar_label: Example program
---


main.cpp:
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
    arma::SpMat<double> mu;
	mu.set_size(L);
	mu.fill(1);
	Parameters<double> param;
	param['mu'] = mu;
	quantumSystem.SelectParameters(param);
    quantumSystem.SelectHamiltonian<KitaevHamiltonian>();
	quantumSystem.Fill(); // fill matrix elements

    return 0;
}
```

Compile with the following:

```bash
g++ main.cpp -o main.exe -O3 -larmadillo -lsolid
```
**Caveat:** make sure that you have installed g++ in version at least 7.4.0

Remember to always add a proper optimalisation option during runing the make file: option `-O3` is recommended. 