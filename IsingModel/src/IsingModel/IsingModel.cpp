#include <fstream>
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

	// Output animation data
	std::string AnimationOutput;

	FGlauberModel* GlauberModel = new FGlauberModel(NumDimensions, Temperature);

	// Iterate over the number of steps
	for (size_t t = 0; t < NumSteps + 1; t++)
	{
		GlauberModel->Update();
		if ((t > 0) && (t % 10 == 0))
		{
			AnimationOutput += GlauberModel->OutputSpins() + "\n\n\n";
		}
	}

	// Save animation output to a file
	std::string AnimationPath = "animation.txt";
	std::ofstream AnimationFile;
	AnimationFile.open(AnimationPath);
	AnimationFile << AnimationOutput;
	AnimationFile.close();

	delete GlauberModel;
}