#pragma once
#include <string>
class Customer{
    public:
        std::string getName();
        void setName(std::string);

        std::string getAddress();
        void setAddress(std::string);

        char getType();
        void setType(char);

        virtual void print();
        Customer(std::string name, std::string address, char type);
        Customer() = default;
        virtual ~Customer();

        virtual std::stringstream exp();
        virtual void loadData(std::istream&);

        friend std::ostream& operator<<(std::ostream& output , Customer& c);
        friend std::istream& operator>>(std::istream& input, Customer& c);
              
    protected:
        std::string name;
        std::string address;
        char type;
};