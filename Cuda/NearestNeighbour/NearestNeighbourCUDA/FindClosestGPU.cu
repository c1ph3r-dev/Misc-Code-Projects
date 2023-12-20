#include <cuda.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

__global__ void FindClosestGPU(float3* points, int* indices, int count)
{
	if (count <= 1) return;

	auto square = [](const auto& num) { return num * num; };

	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < count)
	{
		float3 thisPoint = points[idx];
		float smallestDistSoFar = 3.40282e38f;

		for (int i = 0; i < count; i++)
		{
			if (i == idx) continue;
			float dist = (
				square(thisPoint.x - points[i].x) +
				square(thisPoint.y - points[i].y) +
				square(thisPoint.z + points[i].z)
				);
			if (dist < smallestDistSoFar)
			{
				smallestDistSoFar = dist;
				indices[idx] = i;
			}
		}
	}
}