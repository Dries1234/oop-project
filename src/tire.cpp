#include "classes/tire.h"
#include <iostream>
#include <sstream>
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
    return type;
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
    std::cout << std::endl <<std::endl;
}

Article* Tire::clone(){
    return new Tire(*this);
}

std::stringstream Tire::exp(){
    std::stringstream out;
    out << type << std::endl 
    << name << std::endl 
    << manufacturer << std::endl
    << stock << std::endl
    << diameter <<std::endl
    << price <<std::endl
    << width << std::endl
    << height << std::endl
    << speedIndex << std::endl
    << season << std::endl;
    return out;
}

void Tire::loadData(std::istream& input){
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
    //height
    int height;
    std::getline(input,buffer);
    height = std::stoi(buffer);
    //speedIndex
    std::string speedIndex;
    std::getline(input,speedIndex);
    //season
    char season;
    std::getline(input,buffer);
    season = buffer[0];

    setName(name);
    setManufacturer(manufacturer);
    setStock(stock);
    setDiameter(diameter);
    setPrice(price);
    setWidth(width);
    setHeight(height);
    setSpeedIndex(speedIndex);
    setSeason(season);
    setType('t');
}

Tire::Tire(std::string name, std::string manufacturer,
    int stock, int diameter, float price,
    //Tire specific
    int width, int height, std::string speedIndex, char season)
    :Article(name,manufacturer,stock,diameter,price),
    width(width), height(height), speedIndex(speedIndex), season(season)
{
    type = 't';
}


Tire::~Tire() 
{
    
}
