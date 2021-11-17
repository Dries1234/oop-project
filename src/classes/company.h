#pragma once
#include "customer.h"
#include <string>
class Company : Customer{
    public:
        std::string getVAT();
        void setVAT(std::string);

        int getVolumeDiscount();
        void setVolumeDiscount(int);

        Company();
        ~Company();

    private:
        std::string VAT;
        int volumeDiscount;
};