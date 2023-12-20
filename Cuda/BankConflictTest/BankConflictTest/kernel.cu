#include <cuda.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostream>
#include <conio.h>

typedef unsigned long long uint_64;

struct Coord4D
{
	float x, y, z, w;
	float padding;
};

__global__ void MyKernel(uint_64* time)
{
	__shared__ Coord4D shared[512];
	uint_64 startTime = clock();

	shared[threadIdx.x].x++;

	uint_64 finishTime = clock();
	*time = finishTime - startTime;
}

int main()
{
	uint_64 time;
	uint_64* d_time;
	cudaMalloc(&d_time, sizeof(uint_64));

	for (int i = 0; i < 10; i++)
	{
		MyKernel<<<1, 32>>>(d_time);
		cudaMemcpy(&time, d_time, sizeof(uint_64), cudaMemcpyDeviceToHost);

		// 14 is the overhead for calling clock
		std::cout << "Time: " << (time - 14) / 32 << "\n\n";
	}

	cudaFree(d_time);

	_getch();
	cudaDeviceReset();
	return 0;
}