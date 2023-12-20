#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cuda.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

void FindClosestCPU(float3* points, int* indices, int count)
{
	// Lamda function to calculate square of a value
	auto square = [](const auto& num) { return num * num; };

	// Base case, if there's 1 point don't do anything
	if (count <= 1) return;
	// Loop thru every point
	for (int curPoint = 0; curPoint < count; curPoint++)
	{
		// This variable is nearest sofar, set it to float.max
		float distToClosest = 3.40282e38f;
		// See how far it is from every other point
		for (int i = 0; i < count; i++)
		{
			// Don't check distance to itself
			if (i == curPoint) continue;
			float dist = (
				square(points[curPoint].x - points[i].x) +
				square(points[curPoint].y - points[i].y) +
				square(points[curPoint].z + points[i].z)
			);
			if (dist < distToClosest)
			{
				distToClosest = dist;
				indices[curPoint] = i;
			}
		}
	}
}