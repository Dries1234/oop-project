#include "classes/rim.h"

bool Rim::getAluminium() 
{
    return aluminium;
}

void Rim::setAluminium(bool a) 
{
    aluminium = a;
}

std::string Rim::getColor() 
{
    return color;
}

void Rim::setColor(std::string c) 
{
    color = c;
}

int Rim::getWidth() 
{
    return width;
}

void Rim::setWidth(int w) 
{
    width = w;
}

Rim::Rim() 
{
    
}

Rim::~Rim() 
{
    
}