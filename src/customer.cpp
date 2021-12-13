#include "classes/customer.h"
#include <string>
#include <iostream>
#include <sstream>

std::string Customer::getName() 
{
    return name;
}

void Customer::setName(std::string n) 
{
    name = n;
}

std::string Customer::getAddress() 
{
    return address;
}

void Customer::setAddress(std::string a) 
{
    address = a;
}

char Customer::getType() 
{
    return type;
}

void Customer::setType(char t) 
{
    type = t;
}

void Customer::print(){
    std::cout << "+++++++++++++++++++++++ Customer +++++++++++++++++++++++" <<std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << std::endl;
}

Customer::Customer(std::string name, std::string address, char type)
: name(name), address(address), type(type)
{
    
}


Customer::~Customer() 
{
    
}

Customer* Customer::clone() 
{
    return new Customer(*this);
}

std::stringstream Customer::exp() 
{
    std::stringstream out;
    out << type << std::endl 
    << name << std::endl 
    << address << std::endl;
    return out;
}

void Customer::loadData(std::istream& input) 
{
    //name
    std::string name;
    std::getline(input, name);
    //address
    std::string address;
    std::getline(input,address);

    setName(name);
    setAddress(address);
    setType('p');
}



std::ostream& operator<<(std::ostream& output, Customer& c) 
{
 std::string input = c.exp().str();

 return (output << input);  
}

std::istream& operator>>(std::istream& input, Customer& c) 
{
    c.loadData(input);
    return input;
}
