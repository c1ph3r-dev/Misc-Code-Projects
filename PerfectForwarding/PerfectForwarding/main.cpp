#include <iostream>

class Employee
{
	std::string m_Name;
	int m_Id;

public:
	//Employee(const std::string& name, const int& id) :
	//	m_Name(name), m_Id(id)
	//{
	//	std::cout << "Employee(const std::string& name, const int& id)" << std::endl;
	//}
	template<typename T1, typename T2>
	Employee(T1 name, T2 id) :
		m_Name{ name }, m_Id{ id }
	{
		std::cout << "Employee(const std::string&& name, int&& id)" << std::endl;
	}
};

int main()
{ 
	Employee emp{ "Jon", 100 };
	std::string name{ "Jon" };
	//Employee emp2{ name, 100 };
	return 0;
}