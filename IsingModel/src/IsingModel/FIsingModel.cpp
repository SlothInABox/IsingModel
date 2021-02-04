#include "FIsingModel.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <math.h>

#pragma region FIsingModel
// Constructor
FIsingModel::FIsingModel(const int& N, const double& T) : LatticeSize(N), Temperature(T), Lattice(LatticeSize * LatticeSize)
{
	// Populate with random values [-1, 1]
	for (size_t i = 0; i < LatticeSize * LatticeSize; i++)
	{
		// Convert 1D index to 2D position
		int X = i % LatticeSize;
		int Y = i / LatticeSize;
		// Randomise spin to -1 or 1
		int Spin = (std::rand() % 2) * 2 - 1;

		FNode NewNode = { X, Y, Spin };
		// Add node to lattice
		Lattice[i] = NewNode;
	}
	// Populate nearest neighbours
	for (FNode& Node : Lattice)
	{
		Vector2D NodePosition = Node.GetCoordinates();
		// Get nearest neighbour x and y coordinates
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (abs(i) != abs(j))
				{
					// Periodic boundary conditions
					int X = (NodePosition.X + j) % LatticeSize;
					int Y = (NodePosition.Y + i) % LatticeSize;

					// Find the nearest node index from its coordinates
					int NearestNeighbourIndex = X + LatticeSize * Y;
					Node.AddNeighbour(&Lattice[NearestNeighbourIndex]);
				}
			}
		}
	}
}

std::string FIsingModel::OutputSpins()
{
	for (size_t i = 0; i < LatticeSize; i++)
	{
		for (size_t j = 0; j < LatticeSize; j++)
		{
			FNode* Node = &Lattice[i + LatticeSize * j];
			std::cout << Node->GetSpin();
		}
		std::cout << std::endl;
	}
	return std::string("NONE");
}

void FIsingModel::FlipRandom()
{
	// Select random node for flipping
	FNode* Node = &Lattice[std::rand() % LatticeSize * LatticeSize];
	// Get the energy change from this flip
	int EnergyChange = Node->GetEnergyChange();

	if ((EnergyChange <= 0) || (std::rand() < exp(-EnergyChange / Temperature)))
	{
		Node->FlipSpin();
	}
}

void FIsingModel::Update()
{
	// Give every lattice node a chance to flip
	for (size_t i = 0; i < LatticeSize * LatticeSize; i++)
	{
		FlipRandom();
	}
}

double FIsingModel::GetTotalEnergy()
{
	double TotalEnergy = 0.0;
	for (FNode& Node : Lattice)
	{
		TotalEnergy += Node.GetEnergy();
	}
	TotalEnergy /= 2;
	return TotalEnergy;
}

int FIsingModel::GetMagnetization()
{
	int Magnetization = 0;
	for (FNode& Node : Lattice)
	{
		Magnetization += Node.GetSpin();
	}
	return Magnetization;
}
#pragma endregion

#pragma region FGlauberModel

#pragma endregion