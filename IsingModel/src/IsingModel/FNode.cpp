#include "FNode.h"
#include <random>
#include <iostream>

Vector2D::Vector2D(const int& X, const int& Y) : X(X), Y(Y)
{
}

FNode::FNode() : Coordinates(0, 0), Spin(1), NearestNeighbours()
{
}

FNode::FNode(const int& X, const int& Y, const int& Spin) : Coordinates(X, Y), Spin(Spin), NearestNeighbours()
{
}

Vector2D FNode::GetCoordinates()
{
	return Coordinates;
}

void FNode::AddNeighbour(FNode* Node)
{
	for (FNode*& NearestNeighbour : NearestNeighbours)
	{
		if (NearestNeighbour == NULL)
		{
			NearestNeighbour = Node;
			break;
		}
	}
}

int FNode::GetEnergyChange()
{
	int EnergyChange = 0;

	for (FNode* NearestNeighbour : NearestNeighbours)
	{
		EnergyChange += NearestNeighbour->GetSpin();
	}
	EnergyChange *= -2 * Spin;
	return EnergyChange;
}

void FNode::FlipSpin()
{
	Spin *= -1;
}

void FNode::SetSpin(const int& NewSpin)
{
	Spin = NewSpin;
}

int FNode::GetSpin()
{
	return Spin;
}

int FNode::GetEnergy()
{
	int Energy = 0;

	for (FNode* NearestNeighbour : NearestNeighbours)
	{
		Energy += NearestNeighbour->Spin;
	}
	Energy *= -Spin;
	return Energy;
}

