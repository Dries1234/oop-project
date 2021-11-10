#pragma once

#include <string>
class Article{
    public:
        std::string getName();
        void setName(std::string);

        std::string getManufacturer();
        void setManufacturer(std::string);

        int getStock();
        void setStock(int);

        int getDiameter();
        void setDiameter(int);

        float getPrice();
        void setPrice(float);

        char getType();
        void setType(char);
        
    private:
        std::string name;
        std::string manufacturer;
        int stock;
        int diameter;
        float price;
        char type;
};