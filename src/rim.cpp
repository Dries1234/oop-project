#include "classes/rim.h"
#include <iostream>
#include <sstream>
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
std::stringstream Rim::exp(){
    std::stringstream out;
    out << type << std::endl 
    << name << std::endl 
    << manufacturer << std::endl
    << stock << std::endl
    << diameter <<std::endl
    << price <<std::endl
    << width << std::endl
    << aluminium << std::endl
    << color << std::endl;
    return out;
}

void Rim::loadData(std::istream& input){
    std::string buffer;
    //name
    std::string name;
    std::getline(input, name);
    //manufacturer
    std::string manufacturer;
    std::getline(input, manufacturer);
    //stock
    int stock;
    std::getline(input,buffer);
    stock = std::stoi(buffer);
    //diameter
    int diameter;
    std::getline(input, buffer);
    diameter = std::stoi(buffer);
    //price
    float price;
    std::getline(input,buffer);
    price = std::stof(buffer);
    //width
    int width;
    std::getline(input,buffer);
    width = std::stoi(buffer);
    //aluminium
    bool aluminium;
    std::getline(input,buffer);
    aluminium = std::stoi(buffer);
    //color
    std::string color;
    std::getline(input,color);

    setName(name);
    setManufacturer(manufacturer);
    setStock(stock);
    setDiameter(diameter);
    setPrice(price);
    setWidth(width);
    setAluminium(aluminium);
    setColor(color);
    setType('r');
    
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
