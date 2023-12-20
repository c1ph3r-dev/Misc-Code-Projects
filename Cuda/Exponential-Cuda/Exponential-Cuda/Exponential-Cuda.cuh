#ifndef JONATHAN_RAMPERSAD_EXPONENTIAL_CUDA_H_
#define JONATHAN_RAMPERSAD_EXPONENTIAL_CUDA_H_

#include "Exponential.h"

#include <cuda.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

__global__ void Fitness(int lrgst_expo, int64_t* constants, int sizeOfCons, double* x_vals, double* ranks, int sizeOfSols, double y_val)
{
	auto POW = [](const double& x, const int& exp) {
		if (exp == 0)
			return 1.0;

		double res = x;
		for (int i = 1; i < exp; i++)
		{
			res *= x;
		}

		return res;
		};

	auto ABS = [](const double& n)
		{
			return n < 0 ? n * -1 : n;
		};

	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < sizeOfSols)
	{
		double ans = 0;
		for (int i = lrgst_expo; i >= 0; i--)
			ans += constants[i] * POW(x_vals[idx], (lrgst_expo - i));

		ans -= y_val;
		ranks[idx] = (ans == 0) ? DBL_MAX : ABS(1 / ans);
	}
}

namespace JRAMPERSAD
{
	namespace EXPONENTIAL
	{
		namespace detail
		{
			struct CUDA_SOLUTION
			{
				double x, rank;
				CUDA_SOLUTION() : x(0.0), rank(0.0) {}
				CUDA_SOLUTION(double x_val, double rnk) : x(x_val), rank(rnk) {}
			};
		}

		using namespace detail;

		class ExponentialCUDA : public Function
		{
		public:
			ExponentialCUDA(const unsigned short& Lrgst_expo) : Function(Lrgst_expo) {}

			virtual std::vector<double> solve_x(const double& y_val, const GA_Options& options = GA_Options()) const override;
		};

		std::vector<double> ExponentialCUDA::solve_x(const double& y_val, const GA_Options& options) const
		{
			try
			{
				this->CanPerform();
			}
			catch (const std::exception& e)
			{
				throw e;
			}

			// Create initial random solutions
			std::random_device device;
			std::uniform_real_distribution<double> unif(options.min_range, options.max_range);
			std::vector<CUDA_SOLUTION> solutions;
			int64_t* cons = new int64_t[constants.size()];
			int64_t* d_cons;
			for (int i = 0; i < constants.size(); i++)
				cons[i] = constants[i];

			cudaMalloc(&d_cons, sizeof(int64_t) * constants.size());
			cudaMemcpy(d_cons, cons, sizeof(int64_t) * constants.size(), cudaMemcpyHostToDevice);

			double* x_vals = new double[options.data_size];
			double* ranks = new double[options.data_size];

			double* d_x_vals;
			double* d_ranks;

			cudaMalloc(&d_x_vals, sizeof(double) * options.data_size);
			cudaMalloc(&d_ranks, sizeof(double) * options.data_size);

			solutions.reserve(options.data_size);
			for (unsigned int i = 0; i < options.sample_size; i++)
			{
				x_vals[i] = unif(device);
			}

			for (unsigned int count = 0; count < options.num_of_generations; count++)
			{
				for (unsigned int i = options.sample_size; i < options.data_size; i++)
				{
					x_vals[i] = unif(device);
				}


				// int lrgst_expo, int64_t* constants, int sizeOfCons, double* x_vals, double* ranks, int sizeOfSols, int y_val
				
				cudaMemcpy(d_x_vals, x_vals, sizeof(double) * options.data_size, cudaMemcpyHostToDevice);
				Fitness<<<(options.data_size / 8192) + 1, 512>>>(lrgst_expo, d_cons, (int)(constants.size()), d_x_vals, d_ranks, options.data_size, y_val);
				cudaMemcpy(ranks, d_ranks, sizeof(double) * options.data_size, cudaMemcpyDeviceToHost);

				for (unsigned int i = 0; i < options.data_size; i++)
				{
					solutions.push_back(CUDA_SOLUTION(x_vals[i], ranks[i]));
				}

				std::sort(std::execution::par, solutions.begin(), solutions.end(),
					[](const auto& lhs, const auto& rhs) {
						return lhs.rank > rhs.rank;
					});

				std::vector<CUDA_SOLUTION> sample;
				std::copy(
					solutions.begin(),
					solutions.begin() + options.sample_size,
					std::back_inserter(sample)
				);
				solutions.clear();

				if (count + 1 == options.num_of_generations)
				{
					std::copy(
						sample.begin(),
						sample.end(),
						std::back_inserter(solutions)
					);
					sample.clear();
					break;
				}

				std::uniform_real_distribution<double> m((1 - options.mutation_percentage), (1 + options.mutation_percentage));
				std::for_each(sample.begin(), sample.end(), [&m, &device](auto& s) {
					s.x *= m(device);
					});

				for (unsigned int i = 0; i < options.sample_size; i++)
				{
					x_vals[i] = sample[i].x;
				}
			}
		
			std::sort(solutions.begin(), solutions.end(),
				[](const auto& lhs, const auto& rhs) {
					return lhs.x < rhs.x;
				});

			std::vector<double> ans;
			for (auto& s : solutions)
			{
				ans.push_back(s.x);
			}

			delete[] cons;
			delete[] x_vals;
			delete[] ranks;

			cudaFree(d_cons);
			cudaFree(d_x_vals);
			cudaFree(d_ranks);

			return ans;
		}
	}
}

#endif // JONATHAN_RAMPERSAD_EXPONENTIAL_CUDA_H_