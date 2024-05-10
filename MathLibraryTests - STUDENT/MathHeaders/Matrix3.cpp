#include "Matrix3.h"
#include "Vector3.h"

#include<cmath>
namespace MathClasses
{
	//Column major order.


	Matrix3::Matrix3()
		:m1(1), m2(0), m3(0),
		 m4(0), m5(1), m6(0),
		 m7(0), m8(0), m9(1)
	{
	}
	Matrix3::Matrix3(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
	{
		m1 = a1;
		m2 = a2;
		m3 = a3;
		m4 = a4;
		m5 = a5;
		m6 = a6;
		m7 = a7;
		m8 = a8;
		m9 = a9;
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
		Matrix3 identity;
		identity.m1 = 1;
		identity.m2 = 0;
		identity.m3 = 0;

		identity.m4 = 0;
		identity.m5 = 1;
		identity.m6 = 0;

		identity.m7 = 0;
		identity.m8 = 0;
		identity.m9 = 1;

		return identity;
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
	Matrix3 operator*(const Matrix3 &a, const Matrix3 &b ) 
	{
		
		// m1 m4 m7  
		// m2 m5 m8
		// m3 m6 m9

		Matrix3 sum;
		//use dot of row by collume to get result 1,1.
		
		sum.m1 = Vector3(a.m1, a.m4, a.m7).Dot(Vector3(b.m1, b.m2, b.m3));
		sum.m2 = Vector3(a.m2, a.m5, a.m8).Dot(Vector3(b.m1, b.m2, b.m3));
		sum.m3 = Vector3(a.m3, a.m6, a.m9).Dot(Vector3(b.m1, b.m2, b.m3));

		sum.m4 = Vector3(a.m1, a.m4, a.m7).Dot(Vector3(b.m4, b.m5, b.m6));
		sum.m5 = Vector3(a.m2, a.m5, a.m8).Dot(Vector3(b.m4, b.m5, b.m6));
		sum.m6 = Vector3(a.m3, a.m6, a.m9).Dot(Vector3(b.m4, b.m5, b.m6));

		sum.m7 = Vector3(a.m1, a.m4, a.m7).Dot(Vector3(b.m7, b.m8, b.m9));
		sum.m8 = Vector3(a.m2, a.m5, a.m8).Dot(Vector3(b.m7, b.m8, b.m9));
		sum.m9 = Vector3(a.m3, a.m6, a.m9).Dot(Vector3(b.m7, b.m8, b.m9));

		return sum;
	}
	Vector3 operator*(const Matrix3 &a, const Vector3 &b)
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
