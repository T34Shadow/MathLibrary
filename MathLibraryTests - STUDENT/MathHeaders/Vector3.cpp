#include "Vector3.h"


#include<string>
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
		return	std::to_string(x) + ":" + std::to_string(y) + ":" + std::to_string(z);
		 
	}

	float Vector3::Magnitude()const
	{
		return sqrtf((x * x) + (y * y) + (z * z));
	}

	void Vector3::Normalise()
	{
		float magnitude = Magnitude();

		//if magnitude retures a 0, reture a vector(0,0,0)
		if (magnitude == 0)
		{
			x = 0;
			y = 0;
			z = 0;
		}
		else
		{
			x /= magnitude;
			y /= magnitude;
			z /= magnitude;
		}
		
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
		Vector3 sum;

		sum.x = y * _other.z - z * _other.y;
		sum.y = z * _other.x - x * _other.z;
		sum.z = x * _other.y - y * _other.x;

		return sum;
	}

	float Vector3::Displacement(Vector3 _other)
	{
		return (*this - _other).Magnitude();
	}

	float Vector3::AngleBetween(const Vector3 _other) const
	{
		Vector3 a = Normalised();
		Vector3 b = _other.Normalised();

		float d = a.Dot(_other);

		return acosf(d);
	}

	Vector3 operator+(const Vector3 &a, const Vector3 &b)
	{
		Vector3 sum;

		sum.x = a.x + b.x;
		sum.y = a.y + b.y;
		sum.z = a.z + b.z;

		return sum;
	}

	Vector3 operator-(const Vector3 &a, const Vector3 &b)
	{
		Vector3 sum;
		sum.x = a.x - b.x;
		sum.y = a.y - b.y;
		sum.z = a.z - b.z;
		return sum;
	}

	Vector3 operator*(const Vector3 &_vec, const float &_scalar)
	{
		Vector3 sum;
		sum.x = _vec.x * _scalar;
		sum.y = _vec.y * _scalar;
		sum.z = _vec.z * _scalar;
		return sum;
	}
	Vector3 operator*(const float &_scalar, const Vector3 &_vec)
	{
		Vector3 sum;
		sum.x = _scalar * _vec.x;
		sum.y = _scalar * _vec.y;
		sum.z = _scalar * _vec.z;
		return sum;
	}
	Vector3 operator/(const Vector3 &a, const float &b)
	{
		Vector3 sum;
		sum.x = a.x / b;
		sum.y = a.y / b;
		sum.z = a.z / b;
		return sum;
	}
	Vector3 operator/(const float &a, const Vector3 &b)
	{
		Vector3 sum;
		sum.x = b.x / a;
		sum.y = b.y / a;
		sum.z = b.z / a;
		return sum;
	}
	bool operator==(Vector3 a, Vector3 b)
	{
		
		float threshold = 0.01;

		float resultX = fabsf(a.x - b.x);
		float resultY = fabsf(a.y - b.y);
		float resultZ = fabsf(a.z - b.z);
				
		if ((resultX < threshold) && (resultY < threshold) && (resultZ < threshold))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(Vector3 a, Vector3 b)
	{
		float threshold = 0.01;

		float resultX = fabsf(a.x - b.x);
		float resultY = fabsf(a.y - b.y);
		float resultZ = fabsf(a.z - b.z);

		if ((resultX < threshold) || (resultY < threshold) || (resultZ < threshold))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

