#pragma once

class Customer{
    public:
        std::string getName();
        void setName(std::string);

        std::string getAddress();
        void setAddress(std::string);

        char getType();
        void setType(char);      
    private:
        std::string name;
        std::string address;
        char type;
};