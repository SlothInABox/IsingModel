#include <iostream>
#include "FIsingModel.h"

int main()
{
	std::cout << "Hello world\n";
	IsingModel::FIsingModel* NewModel = new IsingModel::FIsingModel();
	delete NewModel;
}