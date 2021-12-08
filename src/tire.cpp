#include "classes/tire.h"
#include <iostream>
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

char  Tire::getType(){
    return 't';
}
void Tire::print(){
    std::cout << "+++++++++++++++++++++++ Tire +++++++++++++++++++++++" <<std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Manufacturer: " << manufacturer << std::endl;
    std::cout << "Stock: " << stock << std::endl;
    std::cout << "Diameter: " << diameter << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "height: " << height << std::endl;
    std::cout << "speedIndex: " << speedIndex << std::endl;
    std::cout << "season: " << season << std::endl;
}

Tire::Tire(std::string name, std::string manufacturer,
    int stock, int diameter, float price,
    //Tire specific
    int width, int height, std::string speedIndex, char season)
    :Article(name,manufacturer,stock,diameter,price),
    width(width), height(height), speedIndex(speedIndex), season(season)
{

}

Tire::~Tire() 
{
    
}
