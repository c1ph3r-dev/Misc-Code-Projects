#include "../dynamic_array2d.hpp"
#include <iostream>

int main()
{
  using namespace JRAMPERSAD;
  using namespace UTILS;

  darray2d<int> vec2d(2,2,0);
  vec2d.AddColumn(1);
  vec2d.AddRow(1);
  vec2d[0][0] = 1;
  std::cout << "Columns: " << vec2d.GetSizeofColumns() << std::endl;
  std::cout << "Rows: " << vec2d.GetSizeOfRow() << std::endl;
  std::cout << vec2d << std::endl;
}