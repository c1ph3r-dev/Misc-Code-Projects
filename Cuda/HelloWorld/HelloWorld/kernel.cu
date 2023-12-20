#include "cuda_runtime.h"
//#include "device_launch_parameters.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>

__global__ void AddInts(int* a, int* b, int count)
{
	int id = blockIdx.x * blockDim.x + threadIdx.x;
	if (id < count)
	{
		a[id] += b[id];
	}
}

int main()
{
	srand(time(NULL));
	int count = 256 * 256;
	int *h_a = new int[count];
	int *h_b = new int[count];

	for (int i = 0; i < count; i++)
	{
		h_a[i] = rand() % 1000;
		h_b[i] = rand() % 1000;
	}

	std::cout << "Prior to addition:\n";
	for (int i = 0; i < 5; i++)
		std::cout << h_a[i] << " " << h_b[i] << std::endl;

	int *d_a, *d_b;

	if (cudaMalloc(&d_a, sizeof(int) * count) != cudaSuccess)
	{
		delete[] h_a;
		delete[] h_b;
		std::cout << "Nope! No\n";
		return 0;
	}
	if (cudaMalloc(&d_b, sizeof(int) * count) != cudaSuccess)
	{
		std::cout << "Nope! No\n";
		cudaFree(d_a);
		delete[] h_a;
		delete[] h_b;
		return 0;
	}

	if (cudaMemcpy(d_a, h_a, sizeof(int) * count, cudaMemcpyHostToDevice) != cudaSuccess)
	{
		std::cout << "Could not copy!\n";
		cudaFree(d_a);
		cudaFree(d_b);
		delete[] h_a;
		delete[] h_b;
		return 0;
	}

	if (cudaMemcpy(d_b, h_b, sizeof(int) * count, cudaMemcpyHostToDevice) != cudaSuccess)
	{
		std::cout << "Could not copy!\n";
		cudaFree(d_a);
		cudaFree(d_b);
		delete[] h_a;
		delete[] h_b;
		return 0;
	}

	AddInts<<<count / 256 + 1, 256>>>(d_a, d_b, count);

	if (cudaMemcpy(h_a, d_a, sizeof(int) * count, cudaMemcpyDeviceToHost) != cudaSuccess)
	{
		cudaFree(d_a);
		cudaFree(d_b);
		delete[] h_a;
		delete[] h_b;
		std::cout << "Nope!\n";
		return 0;
	}

	std::cout << "After addition:\n";
	for (int i = 0; i < 5; i++)
		std::cout << "It's " << h_a[i] << std::endl;


	cudaFree(d_a);
	cudaFree(d_b);
	delete[] h_a;
	delete[] h_b;

	return 0;
}