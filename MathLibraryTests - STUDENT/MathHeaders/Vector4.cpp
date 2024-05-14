#include "Vector4.h"

#include<cmath>
#include<string>
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
		return	std::to_string(x) + ":" + std::to_string(y) + ":" + std::to_string(z) + ":" + std::to_string(w);
	}

	float Vector4::Magnitude() const
	{
		return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
	}

	float Vector4::Dot(Vector4 _other) const
	{
		return (x * _other.x) + (y * _other.y) + (z * _other.z) + (w * _other.w);
	}

	Vector4 Vector4::Normalised() const
	{
		Vector4 copy = *this;
		copy.Normalise();
		return copy;
	}

	void Vector4::Normalise()
	{
		float magnitude = Magnitude();

		//if magnitude retures a 0, reture a vector(0,0,0)
		if (magnitude == 0)
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}
		else
		{
			x /= magnitude;
			y /= magnitude;
			z /= magnitude;
			w /= magnitude;
		}
	}

	Vector4 Vector4::Cross(Vector4 _other) const
	{
		Vector4 sum;

		sum.x = y * _other.z - z * _other.y;
		sum.y = z * _other.x - x * _other.z;
		sum.z = x * _other.y - y * _other.x;
		sum.w = 0;

		return sum;
	}

	Vector4 operator+(const Vector4 &a,const Vector4 &b)
	{
		Vector4 sum;

		sum.x = a.x + b.x;
		sum.y = a.y + b.y;
		sum.z = a.z + b.z;
		sum.w = a.w + b.w;

		return sum;
	}

	Vector4 operator-(const Vector4 &a, const Vector4 &b)
	{
		Vector4 sum;

		sum.x = a.x - b.x;
		sum.y = a.y - b.y;
		sum.z = a.z - b.z;
		sum.w = a.w - b.w;

		return sum;
	}

	Vector4 operator*(const Vector4& _vec, const float& _scalar)
	{
		Vector4 sum;

		sum.x = _vec.x * _scalar;
		sum.y = _vec.y * _scalar;
		sum.z = _vec.z * _scalar;
		sum.w = _vec.w * _scalar;

		return sum;
	}

	Vector4 operator*(const float &_scalar , const Vector4 &_vec)
	{
		Vector4 sum;
		sum.x = _scalar * _vec.x;
		sum.y = _scalar * _vec.y;
		sum.z = _scalar * _vec.z;
		sum.w = _scalar * _vec.w;
		return sum;
	}

	Vector4 operator/(const Vector4 &a, const float &b)
	{
		Vector4 sum;
		sum.x = a.x / b;
		sum.y = a.y / b;
		sum.z = a.z / b;
		sum.w = a.w / b;
		return sum;
	}


	bool operator==(Vector4 a, Vector4 b)
	{
		float threshold = 0.01;

		float resultX = fabsf(a.x - b.x);
		float resultY = fabsf(a.y - b.y);
		float resultZ = fabsf(a.z - b.z);
		float resultW = fabsf(a.w - b.w);

		if ((resultX < threshold) && (resultY < threshold) && (resultZ < threshold) && (resultW < threshold))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(Vector4 a, Vector4 b)
	{
		float threshold = 0.01;

		float resultX = fabsf(a.x - b.x);
		float resultY = fabsf(a.y - b.y);
		float resultZ = fabsf(a.z - b.z);
		float resultW = fabsf(a.w - b.w);

		if ((resultX < threshold) || (resultY < threshold) || (resultZ < threshold) || (resultW < threshold))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

