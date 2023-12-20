#include <vector>
#include <ostream>

namespace JRAMPERSAD
{
	namespace UTILS
	{
		template <typename T>
		class darray2d
		{
			int num_of_cols = 0, num_of_rows = 0;
			std::vector<std::vector<T>> data;

		public:
			darray2d() = default;
			darray2d(int n_of_cols, int n_of_rows, T default_val = T()) : num_of_cols(n_of_cols), num_of_rows(n_of_rows)
			{
				data.resize(n_of_cols);
				for (auto &col : data)
				{
					col.resize(n_of_rows, default_val);
				}
			}
			void AddRow(T val = T(), int num_to_add = 1)
			{
				for (auto &row : data)
					for (int i = 0; i < num_to_add; i++)
						row.push_back(val);
					
				num_of_rows += num_to_add;
			}
			void AddColumn(T default_val = T(), int num_to_add = 1)
			{
				for(int i = num_of_cols; i < num_of_cols + num_to_add; i++)
				{
					std::vector<T> vec;
					vec.resize(num_of_rows, default_val);
					data.push_back(std::move(vec));
				}
				num_of_cols += num_to_add;
			}

			std::vector<T>& operator[](size_t index) { return data[index]; }
			friend std::ostream& operator<<(std::ostream& os, const darray2d<T>& obj)
			{
				for(size_t i = 0; i < obj.num_of_rows; i++)
				{
					for(size_t j = 0; j < obj.num_of_cols; j++)
						os << obj.data[j][i] << ", ";
					os << '\n';
				}
				return os;
			}

			inline int GetSizeofColumns() const { return data.size(); }
			inline int GetSizeOfRow() const { return data[0].size(); }
		};
	}
}