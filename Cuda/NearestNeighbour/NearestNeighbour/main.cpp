#include <iostream>
#include <conio.h>
#include <ctime>
#include <cuda.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#include "FindClosestCPU.h"

int main()
{
	srand(1);

	// Number of points
	const int count{ 100000 };

	// Array of points
	int* indexOfClosest = new int[count];
	float3* points = new float3[count];

	// Create a list of random points
	for (int i = 0; i < count; i++)
	{
		points[i].x = (float)((rand() % 10000) - 5000);
		points[i].y = (float)((rand() % 10000) - 5000);
		points[i].z = (float)((rand() % 10000) - 5000);
	}

	// This variable is used to keep track of the fastest time so far
	long fastest{ 1000000 };

	// Run the algorithm 20 times
	for (int q = 0; q < 20; q++)
	{
		long startTime = clock();

		// Run the algorithm
		FindClosestCPU(points, indexOfClosest, count);

		long finishTime = clock();

		std::cout << "Run " << q << " took " << (finishTime - startTime) << "ms" << std::endl;

		// If that run was faster update the fastest time so far
		if ((finishTime - startTime) < fastest)
			fastest = (finishTime - startTime);
	}

	// Print out the fastest time
	std::cout << "Fastest time: " << fastest << std::endl;

	// Print the final results to screen
	std::cout << "Final results:\n";
	for (int i = 0; i < 10; i++)
		std::cout << i << "." << indexOfClosest[i] << std::endl;

	//Deallocate ram
	delete[] indexOfClosest;
	delete[] points;

	_getch();

	return 0;
}