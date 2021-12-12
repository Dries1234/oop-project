#pragma once
#include "article.h"
#include <string>
#include <fstream>
class Rim : public Article{
    public:
        bool getAluminium();
        void setAluminium(bool);

        std::string getColor();
        void setColor(std::string);

        int getWidth();
        void setWidth(int);

        char getType();
        void print();
        Article* clone();

        std::stringstream exp();
        void loadData(std::istream&);
        Rim() =default;
        Rim(std::string name, std::string manufacturer,
        int stock, int diameter, float price,
        //Rim
        int width, bool aluminium, std::string color);
        ~Rim();
    private:
        int width;
        bool aluminium;
        std::string color;
        
};