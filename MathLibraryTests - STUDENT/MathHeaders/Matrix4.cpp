#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"

#include<string>
#include<cmath>
namespace MathClasses
{
	Matrix4::Matrix4()
		:m1(1), m2(0), m3(0),m4(0),
		 m5(1), m6(0), m7(0), m8(0),
		 m9(1), m10(0), m11(0), m12(0),
		 m13(0), m14(0), m15(0), m16(0)
	{
	}
	Matrix4::Matrix4(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, float a13, float a14, float a15, float a16)
	{
	}
	Matrix4::Matrix4(float* v)
	{
	}
	std::string Matrix4::ToString() const
	{
		return std::string();
	}
	Matrix4 Matrix4::MakeIdentity()
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeTranslation(float x, float y, float z)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeTranslation(Vector3 v)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeRotateX(float r)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeRotateY(float r)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeRotateZ(float r)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeEuler(float x, float y, float z)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeEuler(Vector3 e)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeScale(float x, float y)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeScale(float x, float y, float z)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::MakeScale(Vector3 s)
	{
		return Matrix4();
	}
	Matrix4 Matrix4::Transposed()
	{
		return Matrix4();
	}
	Matrix4 operator*(Matrix4 a, Matrix4 b)
	{
		return Matrix4();
	}
	Vector4 operator*(Matrix4 a, Vector4 b)
	{
		return Vector4();
	}
	bool operator==(Matrix4 a, Matrix4 b)
	{
		return false;
	}
	bool operator!=(Matrix4 a, Matrix4 b)
	{
		return false;
	}
}
