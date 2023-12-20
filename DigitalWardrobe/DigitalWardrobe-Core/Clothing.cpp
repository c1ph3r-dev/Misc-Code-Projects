#include "Clothing.h"

int Clothing::ID_Count = 0;

Clothing::Clothing(C_Type type, std::string desc, std::string pic, bool bAlreadyExists) :
	ID(ID_Count), Type(type), Desc(desc), Picture(pic)
{
	if(!bAlreadyExists)
		ID_Count++;
}

Clothing::~Clothing()
{
}