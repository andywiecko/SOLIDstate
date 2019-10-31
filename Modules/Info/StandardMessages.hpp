/**
 * @file StandardMessages.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Standard Messages header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef STANDARDMESSAGES_HPP
#define STANDARDMESSAGES_HPP

#include <string>
#include "../Ensemble/Ensemble.hpp"
#include "../QuantumSystem/QuantumSystem.hpp"

namespace solid
{

/**
 * @brief class for showing miscellaneous information 
 */
class StandardMessages
{
public:
	/**
	 * @brief returns ASCII line 
	 */
	static void Line();

	/**
	 * @brief show sectors which are included in the ensemble
	 * 
	 * @param ensemble sectors from Ensemble to display
	 */
	static void ShowSectors(Ensemble &ensemble);

	/**
	 * @brief overloaded function ShowSectors(Ensemble) for QuantumSystem
	 * 
	 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
	 * @tparam T2 data type: double, std::complex<double> are supported
	 * @param qSystem sectors from QuantumSystem to display
	 */
	template <template <typename> class T1, typename T2>
	static void ShowSectors(QuantumSystem<T1, T2> &qSystem);

	/**
	 * @brief info for eigendecomposition
	 */
	static void Eigenmessage(std::string name,int number,std::string target,double tol);

	/**
	 * @brief send Message to the standard output
	 */
	static void Message(std::string);

	/**
	 * @brief (verbose verion) send Message to the standard output
	 * 
	 * send to the standard output if isVerbose option is selected
	 */
	static void vMessage(std::string);
};

} // namespace solid

#endif