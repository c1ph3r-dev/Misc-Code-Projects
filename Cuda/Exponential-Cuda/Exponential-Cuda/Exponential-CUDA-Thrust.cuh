#include "Exponential-Cuda.cuh"

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/sort.h>
#include <thrust/reverse.h>
#include <thrust/execution_policy.h>

namespace JRAMPERSAD
{
	namespace EXPONENTIAL
	{
		using namespace detail;

		class ExponentialCudaThrust : public ExponentialCUDA
		{
		public:
			ExponentialCudaThrust(const unsigned short& Lrgst_expo) : ExponentialCUDA(Lrgst_expo) {}

			virtual std::vector<double> solve_x(const double& y_val, const GA_Options& options = GA_Options()) const override;
		};

		std::vector<double> ExponentialCudaThrust::solve_x(const double& y_val, const GA_Options& options) const
		{
			// Create initial random solutions
			std::random_device device;
			std::uniform_real_distribution<double> unif(options.min_range, options.max_range);

			int64_t* cons = new int64_t[constants.size()];
			int64_t* d_cons;
			for (int i = 0; i < constants.size(); i++)
				cons[i] = constants[i];

			cudaMalloc(&d_cons, sizeof(int64_t) * constants.size());
			cudaMemcpy(d_cons, cons, sizeof(int64_t) * constants.size(), cudaMemcpyHostToDevice);

			thrust::host_vector<double> xVals(options.data_size);
			thrust::device_vector<double> d_xVals(options.data_size);
			thrust::device_vector<double> d_ranks(options.data_size);


			for (unsigned int i = 0; i < options.sample_size; i++)
			{
				xVals[i] = unif(device);
			}

			for (unsigned int count = 0; count < options.num_of_generations; count++)
			{
				for (unsigned int i = options.sample_size; i < options.data_size; i++)
				{
					xVals[i] = unif(device);
				}

				d_xVals = xVals;
				Fitness<<<(options.data_size / 8192) + 1, 512>>> (lrgst_expo, d_cons, (int)(constants.size()), d_xVals, d_ranks, options.data_size, y_val);
				thrust::sort_by_key(thrust::device, d_ranks.begin(), d_ranks.end(), d_xVals.begin());
				thrust::reverse(d_xVals.begin(), d_xVals.end());
				xVals = d_xVals;

				if (count + 1 == options.num_of_generations)
				{
					break;
				}

				std::uniform_real_distribution<double> m((1 - options.mutation_percentage), (1 + options.mutation_percentage));
				auto x_begin = &xVals[0];
				auto x_end = &xVals[options.sample_size - 1];
				std::for_each(x_begin, x_end, [&m, &device](auto& v) {
					v *= m(device);
					});
			}

			std::vector<double> ans;
			for (unsigned int i = 0; i < options.sample_size; i++)
				ans.push_back(xVals[i]);
			
			delete[] cons;
			cudaFree(d_cons);

			return ans;
		}
	}
}