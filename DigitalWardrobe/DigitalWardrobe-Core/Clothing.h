#pragma once
#include <map>
#include <string>

enum class C_Type
{
	Shirt,
	Tee,
	Jacket,
	Hoodie,
	Pants,
	Shoes
};

static std::map<C_Type, char> c_type
{ 
	{C_Type::Shirt, 'A'},
	{C_Type::Tee, 'B'},
	{C_Type::Jacket, 'C'},
	{C_Type::Hoodie, 'D'},
	{C_Type::Pants, 'E'},
	{C_Type::Shoes, 'F'} 
};

class Clothing
{
public:
	Clothing(C_Type type, std::string desc = "", std::string pic = "No Pic provided", bool bAlreadyExists = false);
	~Clothing();

	static int ID_Count;
private:
	int ID;
	C_Type Type;
	std::string Desc;
	std::string Picture;

public:
	C_Type GetType() const { return Type; }
};