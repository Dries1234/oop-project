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

        Customer* clone();

        std::stringstream exp();
        void loadData(std::istream&);
        
        Company(
            std::string name, std::string address, char type,
            //company
            std::string VAT, int volumeDiscount
        );
        Company() =default;
        ~Company();

    private:
        std::string VAT;
        int volumeDiscount;
};