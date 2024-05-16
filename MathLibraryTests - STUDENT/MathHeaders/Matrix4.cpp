#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"

#include<string>
#include<cmath>
namespace MathClasses
{
	Matrix4::Matrix4()
		:m1(0), m2(0), m3(0),m4(0),
		 m5(0), m6(0), m7(0), m8(0),
		 m9(0), m10(0), m11(0), m12(0),
		 m13(0), m14(0), m15(0), m16(0)
	{
	}
	Matrix4::Matrix4(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, float a13, float a14, float a15, float a16)
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
		m10 = a10;
		m11 = a11;
		m12 = a12;
		m13 = a13;
		m14 = a14;
		m15 = a15;
		m16 = a16;


	}
	Matrix4::Matrix4(float* v)
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
		m10 = v[9];
		m11 = v[10];
		m12 = v[11];
		m13 = v[12];
		m14 = v[13];
		m15 = v[14];
		m16 = v[15];
	}
	std::string Matrix4::ToString() const
	{
		return std::to_string(m1) + ":" + std::to_string(m2) + ":" + std::to_string(m3) + ":" + std::to_string(m4) 
			+ ":" + std::to_string(m5) + ":" + std::to_string(m6) + ":" + std::to_string(m7) + ":" + std::to_string(m8)
			+ ":" + std::to_string(m9) + ":" + std::to_string(m10) + ":" + std::to_string(m11) + ":" + std::to_string(m12)
			+ ":" + std::to_string(m13) + ":" + std::to_string(m14) + ":" + std::to_string(m15) + ":" + std::to_string(m16);
	}
	Matrix4 Matrix4::MakeIdentity()
	{
		// m1 m5 m9  m13
		// m2 m6 m10 m14
		// m3 m7 m11 m15
		// m4 m8 m12 m16

		Matrix4 identity;
		identity.m1 = 1;
		identity.m2 = 0;
		identity.m3 = 0;
		identity.m4 = 0;

		identity.m5 = 0;
		identity.m6 = 1;
		identity.m7 = 0;
		identity.m8 = 0;

		identity.m9  = 0;
		identity.m10 = 0;
		identity.m11 = 1;
		identity.m12 = 0;

		identity.m13 = 0;
		identity.m14 = 0;
		identity.m15 = 0;
		identity.m16 = 1;

		return identity;
	}
	Matrix4 Matrix4::MakeTranslation(float x, float y, float z)
	{
		return Matrix4
		(1,0,0,0,
		 0,1,0,0,
		 0,0,1,0,
		 x,y,z,1);
	}
	Matrix4 Matrix4::MakeTranslation(Vector3 v)
	{
		return Matrix4().MakeTranslation(v.x,v.y,v.z);
	}
	Matrix4 Matrix4::MakeRotateX(float r)
	{
		return Matrix4
		(1,0,0,0,
		 0,cosf(r),-sinf(r),0,
		 0, sinf(r), cosf(r),0,
		 0,0,0,1);
		
	}
	Matrix4 Matrix4::MakeRotateY(float r)
	{
		return Matrix4
		(cosf(r), 0, sinf(r), 0,
		 0,1, 0, 0,
		 -sinf(r), 0, cosf(r), 0,
		 0, 0, 0, 1);
	}
	Matrix4 Matrix4::MakeRotateZ(float r)
	{
		return Matrix4
		(cosf(r), sinf(r), 0, 0,
		 -sinf(r), cosf(r), 0, 0,
		 0, 0, 1, 0,
		 0, 0, 0, 1);
	}
	Matrix4 Matrix4::MakeEuler(float pitch, float yaw, float roll)
	{
		Matrix4 x = MakeRotateX(pitch);
		Matrix4 y = MakeRotateY(yaw);
		Matrix4 z = MakeRotateZ(roll);

		return(z * y * x);
	}
	Matrix4 Matrix4::MakeEuler(Vector3 e)
	{
		Matrix4 x = MakeRotateX(e.x);
		Matrix4 y = MakeRotateY(e.y);
		Matrix4 z = MakeRotateZ(e.z);

		return(z * y * x);
	}
	Matrix4 Matrix4::MakeScale(float x, float y)
	{
		return Matrix4
		(x, 0.0f, 0.0f,0.0f,
			0.0f, y, 0.0f,0.0f,
			0.0f, 0.0f, 1.0f,0.0f,
			0.0f,0.0f,0.0f,1.0f);
	}
	Matrix4 Matrix4::MakeScale(float x, float y, float z)
	{
		return Matrix4
		(x, 0.0f, 0.0f, 0.0f,
			0.0f, y, 0.0f, 0.0f,
			0.0f, 0.0f, z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	}
	Matrix4 Matrix4::MakeScale(Vector3 s)
	{
		return Matrix4().MakeScale(s.x, s.y, s.z);
	}
	Matrix4 Matrix4::Transposed()
	{
		return Matrix4();
	}
	Matrix4 operator*(const Matrix4 &a, const Matrix4 &b)
	{
		// m1 m5 m9  m13
		// m2 m6 m10 m14
		// m3 m7 m11 m15
		// m4 m8 m12 m16

		Matrix4 sum;

		sum.m1 = Vector4(a.m1, a.m5, a.m9, a.m13).Dot(Vector4(b.m1, b.m2, b.m3, b.m4));
		sum.m2 = Vector4(a.m2, a.m6, a.m10, a.m14).Dot(Vector4(b.m1, b.m2, b.m3, b.m4));
		sum.m3 = Vector4(a.m3, a.m7, a.m11, a.m15).Dot(Vector4(b.m1, b.m2, b.m3, b.m4));
		sum.m4 = Vector4(a.m4, a.m8, a.m12, a.m16).Dot(Vector4(b.m1, b.m2, b.m3, b.m4));

		sum.m5 = Vector4(a.m1, a.m5, a.m9, a.m13).Dot(Vector4(b.m5, b.m6, b.m7, b.m8));
		sum.m6 = Vector4(a.m2, a.m6, a.m10, a.m14).Dot(Vector4(b.m5, b.m6, b.m7, b.m8));
		sum.m7 = Vector4(a.m3, a.m7, a.m11, a.m15).Dot(Vector4(b.m5, b.m6, b.m7, b.m8));
		sum.m8 = Vector4(a.m4, a.m8, a.m12, a.m16).Dot(Vector4(b.m5, b.m6, b.m7, b.m8));

		sum.m9 = Vector4(a.m1, a.m5, a.m9, a.m13).Dot(Vector4(b.m9, b.m10, b.m11, b.m12));
		sum.m10 = Vector4(a.m2, a.m6, a.m10, a.m14).Dot(Vector4(b.m9, b.m10, b.m11, b.m12));
		sum.m11 = Vector4(a.m3, a.m7, a.m11, a.m15).Dot(Vector4(b.m9, b.m10, b.m11, b.m12));
		sum.m12 = Vector4(a.m4, a.m8, a.m12, a.m16).Dot(Vector4(b.m9, b.m10, b.m11, b.m12));

		sum.m13 = Vector4(a.m1, a.m5, a.m9, a.m13).Dot(Vector4(b.m13, b.m14, b.m15, b.m16));
		sum.m14 = Vector4(a.m2, a.m6, a.m10, a.m14).Dot(Vector4(b.m13, b.m14, b.m15, b.m16));
		sum.m15 = Vector4(a.m3, a.m7, a.m11, a.m15).Dot(Vector4(b.m13, b.m14, b.m15, b.m16));
		sum.m16 = Vector4(a.m4, a.m8, a.m12, a.m16).Dot(Vector4(b.m13, b.m14, b.m15, b.m16));

		return sum;
	}
	Vector4 operator*(Matrix4 a, Vector4 b)
	{
		// m1 m5 m9  m13	x		x
		// m2 m6 m10 m14	y	=	y
		// m3 m7 m11 m15	z		z
		// m4 m8 m12 m16	w		w

		Vector4 sum;

		sum.x = Vector4(a.m1, a.m5, a.m9, a.m13).Dot(Vector4(b.x, b.y, b.z, b.w));
		sum.y = Vector4(a.m2, a.m6, a.m10, a.m14).Dot(Vector4(b.x, b.y, b.z, b.w));
		sum.z = Vector4(a.m3, a.m7, a.m11, a.m15).Dot(Vector4(b.x, b.y, b.z, b.w));
		sum.w = Vector4(a.m4, a.m8, a.m12, a.m16).Dot(Vector4(b.x, b.y, b.z, b.w));

		return sum;
	}
	bool operator==(Matrix4 a, Matrix4 b)
	{
		// m1 m5 m9  m13
		// m2 m6 m10 m14
		// m3 m7 m11 m15
		// m4 m8 m12 m16

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
		float resultm10 = fabsf(a.m10 - b.m10);
		float resultm11 = fabsf(a.m11 - b.m11);
		float resultm12 = fabsf(a.m12 - b.m12);
		float resultm13 = fabsf(a.m13 - b.m13);
		float resultm14 = fabsf(a.m14 - b.m14);
		float resultm15 = fabsf(a.m15 - b.m15);
		float resultm16 = fabsf(a.m16 - b.m16);

		bool column1 = false;
		bool column2 = false;
		bool column3 = false;
		bool column4 = false;

		if ((resultm1 < threshold) && (resultm2 < threshold) && (resultm3 < threshold) && (resultm4 < threshold))
		{
			column1 = true;
		}
		if ((resultm5 < threshold) && (resultm6 < threshold) && (resultm7 < threshold) && (resultm8 < threshold))
		{
			column2 = true;
		}
		if ((resultm9 < threshold) && (resultm10 < threshold) && (resultm11 < threshold) && (resultm12 < threshold))
		{
			column3 = true;
		}
		if ((resultm13 < threshold) && (resultm14 < threshold) && (resultm15 < threshold) && (resultm16 < threshold))
		{
			column4 = true;
		}

		if (column1 && column2 && column3 && column4 == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(Matrix4 a, Matrix4 b)
	{
		if (a == b)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
