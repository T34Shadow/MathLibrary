#include "Matrix3.h"
#include "Vector3.h"

#include<cmath>
namespace MathClasses
{
	Matrix3::Matrix3()
	{
	}
	Matrix3::Matrix3(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
	{
	}
	Matrix3::Matrix3(float* v)
	{
	}
	std::string Matrix3::ToString() const
	{
		return std::string();
	}
	Matrix3 Matrix3::MakeIdentity()
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeTranslation(float x, float y, float z)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeTranslation(Vector3 v)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeRotateX(float r)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeRotateY(float r)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeRotateZ(float r)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeEuler(float x, float y, float z)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeEuler(Vector3 e)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeScale(float x, float y)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeScale(float x, float y, float z)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::MakeScale(Vector3 s)
	{
		return Matrix3();
	}
	Matrix3 Matrix3::Transposed()
	{
		return Matrix3();
	}
	Matrix3 operator*(Matrix3 a, Matrix3 b)
	{
		return Matrix3();
	}
	Vector3 operator*(Matrix3 a, Vector3 b)
	{
		return Vector3();
	}
	bool operator==(Matrix3 a, Matrix3 b)
	{
		return false;
	}
	bool operator!=(Matrix3 a, Matrix3 b)
	{
		return false;
	}
}
