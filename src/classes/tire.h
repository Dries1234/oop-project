#pragma once
#include <string>
#include "article.h"
#include <fstream>

class Tire: public Article{
    public:
        int getWidth();
        void setWidth(int);

        int getHeight();
        void setHeight(int);

        std::string getSpeedIndex();
        void setSpeedIndex(std::string);

        char getSeason();
        void setSeason(char);

        char getType();
        void print();
        Article* clone();

        std::stringstream exp();
        void loadData(std::istream&);
        Tire() =default;
        Tire(std::string name, std::string manufacturer,
        int stock, int diameter, float price,
        //Tire
        int width, int height, std::string speedIndex, char season);
        ~Tire();

    private:
        int width;
        int height;
        std::string speedIndex;
        char season;
};