#include "Colour.h"


using Byte = unsigned char;


std::string MathClasses::Colour::ToString() const
{
    return std::string();
}

MathClasses::Colour::Colour()
{
}

MathClasses::Colour::Colour(Byte r, Byte g, Byte b, Byte a)
{
}

Byte MathClasses::Colour::GetRed() const
{
    return Byte();
}

Byte MathClasses::Colour::GetGreen() const
{
    return Byte();
}

Byte MathClasses::Colour::GetBlue() const
{
    return Byte();
}

Byte MathClasses::Colour::GetAlpha() const
{
    return Byte();
}

void MathClasses::Colour::SetRed(Byte v)
{
}

void MathClasses::Colour::SetGreen(Byte v)
{
}

void MathClasses::Colour::SetAlpha(Byte v)
{
}

bool MathClasses::operator==(Colour a, Colour b)
{
    return false;
}

bool MathClasses::operator!=(Colour a, Colour b)
{
    return false;
}
