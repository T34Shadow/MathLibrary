#include "Vector4.h"
#include<cmath>
namespace MathClasses
{
	Vector4::Vector4()
		: x(0), y(0), z(0), w(0)
	{
	}

	Vector4::Vector4(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	std::string Vector4::ToString() const
	{
		return std::string();
	}

	float Vector4::Magnitude() const
	{
		return 0.0f;
	}

	float Vector4::Dot(Vector4 _other) const
	{
		return 0.0f;
	}

	Vector4 Vector4::Normalised() const
	{
		return Vector4();
	}

	void Vector4::Normalise()
	{
	}

	Vector4 Vector4::Cross(Vector4 _other) const
	{
		return Vector4();
	}

	Vector4 operator+(const Vector4 &a,const Vector4 &b)
	{
		return Vector4();
	}

	Vector4 operator-(const Vector4 &a, const Vector4 &b)
	{
		return Vector4();
	}

	Vector4 operator*(const Vector4 &a, const float &b)
	{
		return Vector4();
	}

	Vector4 operator*(const float &a, const Vector4 &b)
	{
		return Vector4();
	}

	Vector4 operator/(const Vector4 &a, const float &b)
	{
		return Vector4();
	}


	bool operator==(Vector4 a, Vector4 b)
	{
		return false;
	}

	bool operator!=(Vector4 a, Vector4 b)
	{
		return false;
	}
}

