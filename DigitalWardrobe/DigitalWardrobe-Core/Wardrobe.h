#pragma once
#include "Clothing.h"

#include <vector>

class Wardrobe
{
public:
	Wardrobe() = default;
	~Wardrobe() = default;

	void AddClothing(Clothing clothing);


	/***
	* Option:
	* 0 - Default (Hoodie fit .33, Shirt Fit .33, Tee Fit (w/jacket .5, wo/jacket .5) .33)
	* 1 - Shirt Jacket .25 and Defaults drop from .33 to .25
	* 2 - Hoodie Fit Guranteed
	* 3 - Shirt Fit Guranteed
	* 4 - Tee Fit with Jacket .5, without Jacket .5
	***/
	void GenOutfit(int option = 0);
private:
	std::vector<Clothing> Shirts;
	std::vector<Clothing> Tees;
	std::vector<Clothing> Jackets;
	std::vector<Clothing> Hoodies;
	std::vector<Clothing> Pants;
	std::vector<Clothing> Shoes;

};