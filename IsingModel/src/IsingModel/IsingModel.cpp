#include <iostream>
#include <random>
#include "FIsingModel.h"

int main()
{
	// Random seed
	std::srand(time(0));
	
	// Get user input
	int NumDimensions;
	double Temperature;
	int NumSteps;
	std::cout << "Enter number of dimensions: ";
	std::cin >> NumDimensions;
	std::cout << "Enter temperature: ";
	std::cin >> Temperature;
	std::cout << "Enter number of steps: ";
	std::cin >> NumSteps;

	FIsingModel* IsingModel = new FIsingModel(NumDimensions, Temperature);

	// Iterate over the number of steps
	for (size_t t = 0; t < NumSteps + 1; t++)
	{
		IsingModel->Update();
		if ((t > 0) && (t % 10 == 0))
		{
			IsingModel->GetMagnetization();
		}
	}

	delete IsingModel;
}