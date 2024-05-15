#include "Matrix3.h"
#include "Vector3.h"

#include<string>
#include<cmath>
namespace MathClasses
{
	//Column major order.


	Matrix3::Matrix3()
		:m1(0), m2(0), m3(0),
		 m4(0), m5(0), m6(0),
		 m7(0), m8(0), m9(0)
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
	Matrix3::Matrix3(float* v) //arrays
	{
		m1 = v[0];
		m2 = v[1];
		m3 = v[2];
		m4 = v[3];
		m5 = v[4];
		m6 = v[5];
		m7 = v[6];
		m8 = v[7];
		m9 = v[8];
	}
	std::string Matrix3::ToString() const
	{
		return std::to_string(m1) + ":" + std::to_string(m2) + ":" + std::to_string(m3)
	   + ":" + std::to_string(m4) + ":" + std::to_string(m5) + ":" + std::to_string(m6)
	   + ":" + std::to_string(m7) + ":" + std::to_string(m8) + ":" + std::to_string(m9);
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
		// m1 m4 m7  
		// m2 m5 m8
		// m3 m6 m9
		return Matrix3
			(1,0,0,
			 0,1,0,
			 x,y,z);
	}
	Matrix3 Matrix3::MakeTranslation(Vector3 v)
	{
		return Matrix3().MakeTranslation(v.x,v.y,v.z);
	}
	Matrix3 Matrix3::MakeRotateX(float r)
	{
		return Matrix3
			(1, 0,		 0,
			 0, cosf(r), -sinf(r),
			 0, sinf(r), cosf(r));
	}
	Matrix3 Matrix3::MakeRotateY(float r)
	{
		return Matrix3
			(cosf(r), 0, sinf(r),
			 0,		  1, 0,
			-sinf(r), 0, cosf(r));
	}
	Matrix3 Matrix3::MakeRotateZ(float r)
	{
		return Matrix3
			(cosf(r), sinf(r), 0,
			-sinf(r), cosf(r), 0,
			 0,		  0,	   1);
	}
	Matrix3 Matrix3::MakeEuler(float pitch, float yaw, float roll)
	{
		Matrix3 x = MakeRotateX(pitch);
		Matrix3 y = MakeRotateY(yaw);
		Matrix3 z = MakeRotateZ(roll);

		return (z * y * x);
	}
	Matrix3 Matrix3::MakeEuler(Vector3 e)
	{
		Matrix3 x = MakeRotateX(e.x);
		Matrix3 y = MakeRotateY(e.y);
		Matrix3 z = MakeRotateZ(e.z);

		return (z * y * x);
	}
	Matrix3 Matrix3::MakeScale(float x, float y)
	{
		return Matrix3
			(x, 0.0f, 0.0f,
			 0.0f, y, 0.0f,
			 0.0f, 0.0f, 1.0f);
	}
	Matrix3 Matrix3::MakeScale(float x, float y, float z)
	{
		return Matrix3
			(x, 0.0f, 0.0f,
			 0.0f, y, 0.0f,
			 0.0f, 0.0f, z);
	}
	Matrix3 Matrix3::MakeScale(Vector3 s)
	{
		return Matrix3().MakeScale(s.x, s.y, s.z);
	}
	Matrix3 Matrix3::Transposed()
	{
		//Transposed	//This
		//m1 m2 m3		m1 m4 m7  
		//m4 m5 m6		m2 m5 m8
		//m7 m8 m9		m3 m6 m9

		Matrix3 transposed;
		
		transposed.m1 = this->m1;
		transposed.m4 = this->m2;
		transposed.m7 = this->m3;
		transposed.m2 = this->m4;
		transposed.m5 = this->m5;
		transposed.m8 = this->m6;
		transposed.m3 = this->m7;
		transposed.m6 = this->m8;
		transposed.m9 = this->m9;

		return transposed;
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

		// m1 m4 m7		x		x
		// m2 m5 m8	 *	y   =   y
		// m3 m6 m9		z		z

		Vector3 sum;

		sum.x = Vector3(a.m1, a.m4, a.m7).Dot(Vector3(b.x, b.y, b.z));
		sum.y = Vector3(a.m2, a.m5, a.m8).Dot(Vector3(b.x, b.y, b.z));
		sum.z = Vector3(a.m3, a.m6, a.m9).Dot(Vector3(b.x, b.y, b.z));

		return sum;
	}
	bool operator==(Matrix3 a, Matrix3 b)
	{

		float threshold = 0.01;

		float resultm1 = fabsf(a.m1 - b.m1);
		float resultm2 = fabsf(a.m2 - b.m2);
		float resultm3 = fabsf(a.m3 - b.m3);
		float resultm4 = fabsf(a.m4 - b.m4);
		float resultm5 = fabsf(a.m5 - b.m5);
		float resultm6 = fabsf(a.m6 - b.m6);
		float resultm7 = fabsf(a.m7 - b.m7);
		float resultm8 = fabsf(a.m8 - b.m8);
		float resultm9 = fabsf(a.m9 - b.m9);

		bool row1 = false;
		bool row2 = false;
		bool row3 = false;

		if ((resultm1 < threshold) && (resultm2 < threshold) && (resultm3 < threshold))
		{
			row1 = true;
		}
		if ((resultm4 < threshold) && (resultm5 < threshold) && (resultm6 < threshold))
		{
			row2 = true;
		}
		if ((resultm7 < threshold) && (resultm8 < threshold) && (resultm9 < threshold))
		{
			row3 = true;
		}

		if (row1 && row2 && row3 == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(Matrix3 a, Matrix3 b)
	{
		return false;
	}
}
