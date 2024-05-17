#include "Colour.h"

#include<string>

using Byte = unsigned char;


std::string MathClasses::Colour::ToString() const
{
    return std::string();
}

MathClasses::Colour::Colour()
    :colour{255}
{ 
}

MathClasses::Colour::Colour(Byte red, Byte green, Byte blue, Byte alpha)
{
    colour = (red << 24) | (green << 16) | (blue << 8) | alpha;
}

Byte MathClasses::Colour::GetRed() const
{
    return colour >> 24;
}

Byte MathClasses::Colour::GetGreen() const
{
    return colour >> 16;
}

Byte MathClasses::Colour::GetBlue() const
{
    return colour >> 8;
}



Byte MathClasses::Colour::GetAlpha() const
{
    return colour;
}

void MathClasses::Colour::SetRed(Byte red)
{
    unsigned int v = (unsigned int)red << 24;

    colour = colour & 0x00FFFFFF;
    
    colour = colour | v;
}

void MathClasses::Colour::SetGreen(Byte green)
{
    unsigned int v = (unsigned int)green << 16;

    colour = colour & 0xFF00FFFF;

    colour = colour | v;
}

void MathClasses::Colour::SetBlue(Byte blue)
{
    unsigned int v = (unsigned int)blue << 8;

    colour = colour & 0xFFFF00FF;

    colour = colour | v;
}

void MathClasses::Colour::SetAlpha(Byte alpha)
{
    unsigned int v = (unsigned int)alpha;

    colour = colour & 0xFFFFFF00;

    colour = colour | v;
}

bool MathClasses::operator==(Colour a, Colour b)
{
    if (a.colour == b.colour)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MathClasses::operator!=(Colour a, Colour b)
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
