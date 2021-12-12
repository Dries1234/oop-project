#include "classes/company.h"
#include <string>
#include <iostream>
#include <sstream>

std::string Company::getVAT() 
{
    return VAT;   
}

void Company::setVAT(std::string v) 
{
    VAT = v;
}

int Company::getVolumeDiscount() 
{
    return volumeDiscount;
}

void Company::setVolumeDiscount(int vold) 
{
    volumeDiscount = vold;
}
void Company::print(){
    std::cout << "+++++++++++++++++++++++ Customer +++++++++++++++++++++++" <<std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "VAT: " << VAT << std::endl;
    std::cout << "VolumeDiscount: " << volumeDiscount << std::endl;

}

std::stringstream Company::exp(){
    std::stringstream out;
    out << type << std::endl 
    << name << std::endl 
    << address << std::endl
    << VAT << std::endl
    << volumeDiscount << std::endl;
    return out;
}

void Company::loadData(std::istream& input) 
{
    std::string buffer;
    // name
    std::string name;
    std::getline(input, name);
    // address
    std::string address;
    std::getline(input,address);
    // VAT
    std::string VAT;
    std::getline(input, VAT);
    // volumeDiscount
    int volumeDiscount;
    std::getline(input,buffer);
    volumeDiscount = stoi(buffer);


    setName(name);
    setAddress(address);
    setVAT(VAT);
    setVolumeDiscount(volumeDiscount);
    setType('c');   
}

Company::Company(
    std::string name, std::string address, char type,
            //company
    std::string VAT, int volumeDiscount
) : Customer(name,address,type), VAT(VAT), volumeDiscount(volumeDiscount)
{
    
}

Company::~Company() 
{
    
}
