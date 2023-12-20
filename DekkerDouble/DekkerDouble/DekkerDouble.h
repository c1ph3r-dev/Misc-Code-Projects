#pragma once
#include <iostream>
#include <cmath>

class DekkerDouble
{
	double R, r;
	DekkerDouble(double R, double r) { this->R = R; this->r = r; }

public:
	DekkerDouble() : R(0.0), r(0.0) {}

	DekkerDouble operator+(DekkerDouble const& other);
	DekkerDouble operator-(DekkerDouble const& other);

	void operator+=(DekkerDouble& other);
	void operator-=(DekkerDouble& other);

	operator double() const
	{
		return R;
	}

	static DekkerDouble MakeDekkerDouble(double d)
	{
		DekkerDouble res{};
		res.R = d;

		return res;
	}

	friend std::ostream& operator<<(std::ostream& os, const DekkerDouble& obj)
	{
		os << obj.R << " + " << obj.r;
		return os;
	}
};

DekkerDouble DekkerDouble::operator+(DekkerDouble const& other)
{
	DekkerDouble res{};
	res.R = R + other.R;
	res.r = 0.0;

	if (abs(R) > abs(other.R))
		res.r = R - res.R + other.R + other.r + r;
	else
		res.r = other.R - res.R + R + r + other.r;

	return DekkerDouble{ (res.R + res.r), (res.R - (res.R + res.r) + res.r) };
}

DekkerDouble DekkerDouble::operator-(DekkerDouble const& other)
{
	DekkerDouble res{};
	res.R = R - other.R;
	res.r = 0.0;

	if (abs(R) > abs(other.R))
		res.r = R - res.R - other.R - other.r + r;
	else
		res.r = (-other.R) - res.R + R + r - other.r;

	return DekkerDouble{ (res.R + res.r), (res.R - (res.R + res.r) + res.r) };
}

void DekkerDouble::operator+=(DekkerDouble& other)
{
	DekkerDouble res{};
	res.R = R + other.R;
	res.r = 0.0;

	if (abs(R) > abs(other.R))
		res.r = R - res.R + other.R + other.r + r;
	else
		res.r = other.R - res.R + R + r + other.r;

	DekkerDouble C = { (res.R + res.r), (res.R - (res.R + res.r) + res.r) };
	other.R = C.R;
	other.r = C.r;
}

void DekkerDouble::operator-=(DekkerDouble& other)
{
	DekkerDouble res{};
	res.R = R + other.R;
	res.r = 0.0;

	if (abs(R) > abs(other.R))
		res.r = R - res.R - other.R - other.r + r;
	else
		res.r = (-other.R) - res.R + R + r - other.r;

	DekkerDouble C = { (res.R + res.r), (res.R - (res.R + res.r) + res.r) };
	other.R = C.R;
	other.r = C.r;
}