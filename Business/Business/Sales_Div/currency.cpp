#include "currency.h"

TTD USD::toTTD() const
{
	return TTD(Val * 7.f);
}

USD TTD::toUSD() const
{
	return USD(Val / 7.f);
}