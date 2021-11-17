#pragma once
#include <string>
#include <string>

class Tire{
    public:
        int getWidth();
        void setWidth(int);

        int getHeight();
        void setHeight(int);

        std::string getSpeedIndex();
        void setSpeedIndex(std::string);

        char getSeason();
        void setSeason(char);

        Tire();
        ~Tire();

    private:
        int width;
        int height;
        std::string speedIndex;
        char season;
};