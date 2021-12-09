#include "classes/customer.h"
#include <string>
#include <iostream>

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
