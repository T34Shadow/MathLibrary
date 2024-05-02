#include "Vector3.h"

#include<cmath>
namespace MathClasses
{
	//Defualt constructor
	Vector3::Vector3()
		: x(0), y(0), z(0)
	{
	}

	//Basic constructor
	Vector3::Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	std::string Vector3::ToString() const
	{
		return std::string();
	}

	float Vector3::Magnitude()const
	{
		return sqrtf((x * x) + (y * y) + (z * z));
	}

	void Vector3::Normalise()
	{
		float mag = Magnitude();

		x /= mag;
		y /= mag;
		z /= mag;
	}

	Vector3 Vector3::Normalised() const
	{
		Vector3 copy = *this;
		copy.Normalise();
		return copy;
	}

	float Vector3::Dot(const Vector3 _other)const 
	{
		return (x * _other.x) + (y * _other.y) + (z * _other.z);
	}

	Vector3 Vector3::Cross(const Vector3 _other) const
	{
		return Vector3(y * _other.z - z * _other.y,
					   z * _other.x - x * _other.z,
					   x * _other.y - y * _other.x);
	}

	float Vector3::AngleBetween(const Vector3 _other) const
	{
		Vector3 a = Normalised();
		Vector3 b = _other.Normalised();

		float d = a.Dot(_other);

		return acosf(d);
	}

	Vector3 operator+(Vector3 a, Vector3 b)
	{
		return Vector3();
	}

	Vector3 operator-(Vector3 a, Vector3 b)
	{
		return Vector3();
	}

	Vector3 operator*(Vector3 _vec, float _scalar)
	{
		return Vector3();
	}
	Vector3 operator*(float _scalar, Vector3 _vec)
	{
		return Vector3();
	}
	bool operator==(Vector3 a, Vector3 b)
	{
		return false;
	}
	bool operator!=(Vector3 a, Vector3 b)
	{
		return false;
	}
}

