#include "classes/rim.h"
#include <iostream>
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

char Rim::getType(){
    return type;
}
void Rim::print(){
    std::cout << "+++++++++++++++++++++++ Rim +++++++++++++++++++++++" <<std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Manufacturer: " << manufacturer << std::endl;
    std::cout << "Stock: " << stock << std::endl;
    std::cout << "Diameter: " << diameter << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Aluminium: " << aluminium << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << std::endl <<std::endl;

}
Article* Rim::clone(){
    return new Rim(*this);
}

Rim::Rim(std::string name, std::string manufacturer,
        int stock, int diameter, float price,
        //Rim specific
        int width, bool aluminium, std::string color)
    : Article(name, manufacturer, stock, diameter, price),
        width(width), aluminium(aluminium), color(color)
{
    type = 'r';
}

Rim::~Rim() 
{
    
}
