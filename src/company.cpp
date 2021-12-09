#include "classes/company.h"
#include <string>
#include <iostream>

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
