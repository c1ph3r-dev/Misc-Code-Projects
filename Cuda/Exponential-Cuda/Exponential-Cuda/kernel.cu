#include "Exponential-Cuda.cuh"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostream>
#include <ostream>
#include <chrono>

namespace TIMER {
	struct Timer
	{
		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::duration<float> duration;

		Timer()
		{
			Reset();
		}

		~Timer()
		{

		}

		inline void Reset() noexcept
		{
			start = std::chrono::high_resolution_clock::now();
		}

		void SetEnd() noexcept
		{
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;
		}

		inline float GetTimeInMS() const noexcept
		{
			return float(duration.count() * 1000.f);
		}

		inline float GetTimeInS() const noexcept
		{
			return float(duration.count());
		}
	};
}

int main()
{
	using namespace JRAMPERSAD::EXPONENTIAL;

	std::vector<int64_t> vec = { 1, -6, 11, -6 };

	Function g(3);
	g.SetConstants(vec);
	ExponentialCUDA g_CUDA(3);
	g_CUDA.SetConstants(vec);

	GA_Options options;
	options.mutation_percentage = 0.005;
	options.num_of_generations = 25;
	options.sample_size = 1000;
	options.data_size = 5000000;
	options.min_range = -100;
	options.max_range = 100;

	TIMER::Timer t;
	auto res = g.get_real_roots(options);
	t.SetEnd();

	TIMER::Timer t_CUDA;
	res = g_CUDA.get_real_roots(options);
	t_CUDA.SetEnd();

	std::cout << "CPU took: " << t.GetTimeInMS() << "ms\n";
	std::cout << "GPU took: " << t_CUDA.GetTimeInMS() << "ms\n";
}