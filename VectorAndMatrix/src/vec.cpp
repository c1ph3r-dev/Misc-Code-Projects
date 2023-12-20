#include "../include/vec.h"

namespace JRAMPERSAD
{
  namespace VECTOR
  {
		Vec& Vec::operator+=(Vec& other)
		{
			return Vec(x+other.x, y+other.y, z+other.z, w+other.w);
		}

		Vec& Vec::operator*=(float val)
		{
			return Vec(x*val, y*val, z*val, w*val);
		}

		float Vec::Magnitude() const
		{
			auto sqr = [](auto& val){ return val * val; };

			return sqr(x) + sqr(y) + sqr(z) + sqr(w);
		}

		Vec& Vec::Normalize() const
		{
			auto res = *this;
			res *= (float)(1 / res.Magnitude());
			return res;
		}

		Vec& Vec::CrossProduct(const Vec& other) const
		{

		}

		float Vec::DotProduct(const Vec& other) const 
		{
			return (x * other.x) + (y * other.y) + (z * other.z) + (w * other.w);
		}
  }
}