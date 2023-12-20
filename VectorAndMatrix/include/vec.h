#include <vector>

namespace JRAMPERSAD
{
  namespace VECTOR
  {
    class Vec
    {
      float x, y, z, w;

    protected:
      Vec(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) {}
    public:
      virtual ~Vec() = default;
      Vec(const Vec& other) = default;
      Vec(Vec&& other) = default;
      Vec& operator=(Vec& other) = default;
      Vec& operator=(Vec&& other) = default;

      virtual Vec& operator+=(Vec& other);
      virtual Vec& operator*=(float val);

      virtual float Magnitude() const;
      virtual Vec& Normalize() const;
      virtual Vec& CrossProduct(const Vec& other) const;
      virtual float DotProduct(const Vec& other) const;
    }
  }
}