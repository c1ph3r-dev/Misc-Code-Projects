#include "Wardrobe.h"

#include <cstdlib> 
#include <ctime> 

void Wardrobe::AddClothing(Clothing clothing)
{
	switch (clothing.GetType())
	{
	default:
		break;
	case C_Type::Shirt:
		Shirts.push_back(clothing);
		break;
	case C_Type::Tee:
		Tees.push_back(clothing);
		break;
	case C_Type::Jacket:
		Jackets.push_back(clothing);
		break;
	case C_Type::Hoodie:
		Hoodies.push_back(clothing);
		break;
	case C_Type::Pants:
		Pants.push_back(clothing);
		break;
	case C_Type::Shoes:
		Shoes.push_back(clothing);
	}
}

void Wardrobe::GenOutfit(int option)
{
	std::srand((unsigned)std::time(0));

	int chance = 3;
	int choice;
	bool temp = true;

	int r_Shirt = rand() % Shirts.size();
	int r_Tee = rand() % Tees.size();
	int r_Jacket = rand() % Jackets.size();
	int r_Hoodie = rand() % Hoodies.size();
	int r_Pants = rand() % Pants.size();
	int r_Shoes = rand() % Shoes.size();

	if (option == 1)
	{
		chance = 4;
	}
	else
	{
		temp = false;
		switch (option)
		{
		default:
			break;
		case 2:
			choice = 1;
			break;
		case 3:
			choice = 2;
			break;
		case 4:
			choice = 3;
			break;
		}
	}
	
	if (temp)
	{
		choice = std::rand() % chance;
	}

	switch (choice)
	{
	default:
		break;
	case 1:
		break;
	case 2:
		
	}

}