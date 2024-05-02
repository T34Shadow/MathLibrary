#pragma once

#include <string>

namespace MathClasses
{

    struct Vector3 
    {
        float x;
        float y;
        float z;

        Vector3();
        Vector3(float _x, float _y, float _z);       

        std::string ToString() const;
    
        float Magnitude() const;
        Vector3 Normalised() const;
        void Normalise();
        float Dot(Vector3 _other) const;
        Vector3 Cross(Vector3 _other) const;
        float AngleBetween(const Vector3 _other) const;

        friend Vector3 operator+(Vector3 a, Vector3 b);
        friend Vector3 operator-(Vector3 a, Vector3 b);
        friend Vector3 operator*(Vector3 a, float b);
        friend Vector3 operator*(float a, Vector3 b);

        friend bool operator==(Vector3 a, Vector3 b);
        friend bool operator!=(Vector3 a, Vector3 b);
    };
}
