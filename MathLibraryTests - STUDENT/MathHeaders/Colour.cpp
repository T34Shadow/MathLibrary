#include "Colour.h"


using Byte = unsigned char;


std::string MathClasses::Colour::ToString() const
{
    return std::string();
}

MathClasses::Colour::Colour()
{ 
}

MathClasses::Colour::Colour(Byte red, Byte green, Byte blue, Byte alpha)
{
    colour = (red << 24) | (blue << 16) | (green << 8) | alpha;
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

void MathClasses::Colour::SetBlue(Byte v)
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
