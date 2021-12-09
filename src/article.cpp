#include "classes/article.h"
#include <iostream>

std::string Article::getName()
{
    return name;
}

void Article::setName(std::string n)
{
    name = n;
}

std::string Article::getManufacturer()
{
    return manufacturer;
}

void Article::setManufacturer(std::string m)
{
    manufacturer = m;
}

int Article::getStock()
{
    return stock;
}

void Article::setStock(int s)
{
    stock = s;
}

int Article::getDiameter()
{
    return diameter;
}

void Article::setDiameter(int d)
{
    diameter = d;
}

float Article::getPrice()
{
    return price;
}

void Article::setPrice(float p)
{
    price = p;
}

char Article::getType()
{
    return type;
}

void Article::setType(char t)
{
    type = t;
}

void Article::print(){
    std::cout << "+++++++++++++++++++++++ Article +++++++++++++++++++++++" <<std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Manufacturer: " << manufacturer << std::endl;
    std::cout << "Stock: " << stock << std::endl;
    std::cout << "Diameter: " << diameter << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << std::endl <<std::endl;

}



Article::Article(std::string name, std::string manufacturer, int stock, int diameter, float price)
: name(name), manufacturer(manufacturer), stock(stock), diameter(diameter), price(price)
{

}
    

Article::~Article() 
{
    
}
