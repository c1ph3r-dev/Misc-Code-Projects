#pragma once

#include <iostream>

class USD
{
	float Val;
public:
	USD(float val) : Val(val) {}
	~USD() = default;

	class TTD toTTD() const;
	inline float value() const { return Val; }
	USD& operator+=(const USD& obj)
	{
		this->Val += obj.Val;
		return *this;
	}
};

class TTD
{
	float Val;
public:
	TTD(float val) : Val(val) {}
	~TTD() = default;

	class USD toUSD() const;
	inline float value() const { return Val; }
	TTD& operator+=(const TTD& obj)
	{
		this->Val += obj.Val;
		return *this;
	}
};

inline USD operator+(USD val1, const USD& val2)
{
	val1 += val2;
	return val1;
}

inline TTD operator+(TTD val1, const TTD& val2)
{
	val1 += val2;
	return val1;
}

static std::ostream& operator<<(std::ostream& os, const USD& obj)
{
	os.precision(2);
	os << "$" << obj.value() << "USD";
	return os;
}

static std::ostream& operator<<(std::ostream& os, const TTD& obj)
{
	os.precision(2);
	os << "$" << obj.value() << "TTD";
	return os;
}