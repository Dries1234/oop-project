#pragma once
#include "article.h"
#include <string>
class Rim : Article{
    public:
        bool getAluminium();
        void setAluminium(bool);

        std::string getColor();
        void setColor(std::string);

        int getWidth();
        void setWidth(int);

        Rim();
        ~Rim();
    private:
        bool aluminium;
        std::string color;
        int width;
};