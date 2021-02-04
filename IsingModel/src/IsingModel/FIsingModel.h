#pragma once
#include <vector>
#include <array>
#include <string>
#include "FNode.h"

/** The base simulation object */
class FIsingModel
{
public:
	// Constructor definition
	FIsingModel(const int& N, const double& T);

	// Get string output
	std::string OutputSpins();

	// Method to update the spins by randomly flipping a number of them.
	void Update();

	// Calculate the total energy
	double GetTotalEnergy();

	// Calculate the total magnetization
	int GetMagnetization();

protected:
	unsigned int LatticeSize;
	double Temperature;

	std::vector<FNode> Lattice;

	// String of the spin history (for animation)
	std::string SpinHistory;

	// Method for flipping a random spin
	void FlipRandom();
};