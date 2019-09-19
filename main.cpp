#include "Modules/SOLIDstate.h"

int main()
{

	Operator<cx_mat> ham = Factory::CreateHamiltonian();
	ham.matrixElements;
	ham.matrixElements.print();
	return 0;
}
