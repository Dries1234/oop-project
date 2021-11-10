#pragma once
#include "customer.h"
class Company : Customer{
    public:
        std::string getVAT();
        void setVAT(std::string);

        int getVolumeDiscount();
        void setVolumeDiscount(int);

    private:
        std::string VAT;
        int volumeDiscount;
};