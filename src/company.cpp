#include "classes/company.h"
#include <string>

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

Company::Company() 
{
    
}

Company::~Company() 
{
    
}
