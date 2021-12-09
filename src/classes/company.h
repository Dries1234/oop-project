#pragma once
#include "customer.h"
#include <string>
class Company : public Customer{
    public:
        std::string getVAT();
        void setVAT(std::string);

        int getVolumeDiscount();
        void setVolumeDiscount(int);

        void print();
        Company(
            std::string name, std::string address, char type,
            //company
            std::string VAT, int volumeDiscount
        );
        ~Company();

    private:
        std::string VAT;
        int volumeDiscount;
};