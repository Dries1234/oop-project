#include "classes/tire.h"

int Tire::getWidth() 
{
    return width;
}

void Tire::setWidth(int w) 
{
    width = w;
}

int Tire::getHeight() 
{
    return height;
}

void Tire::setHeight(int h) 
{
    height = h;
}

std::string Tire::getSpeedIndex() 
{
    return speedIndex;
}

void Tire::setSpeedIndex(std::string s) 
{
    speedIndex = s;
}

char Tire::getSeason() 
{
    return season;
}

void Tire::setSeason(char se) 
{
    season = se;
}

Tire::Tire() 
{
    
}

Tire::~Tire() 
{
    
}
