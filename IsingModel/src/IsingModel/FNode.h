#pragma once
#include <array>

struct Vector2D
{
	int X;
	int Y;

	// Constructor - for quickly setting values in initialiser lists
	Vector2D(const int& X, const int& Y);
};

class FNode
{
public:
	FNode();
	FNode(const int& X, const int& Y, const int& Spin);

	Vector2D GetCoordinates();

	void AddNeighbour(FNode* Node);
	
	// Get the change in energy that would occur if this spin was flipped
	int GetEnergyChange();

	void FlipSpin();

	void SetSpin(const int& NewSpin);

	int GetSpin();

	int GetEnergy();

private:
	// Position of the node
	Vector2D Coordinates;

	int Spin;

	std::array<FNode*, 4> NearestNeighbours;

};

