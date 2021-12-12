#pragma once
#include <fstream>
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

        virtual char getType() = 0;
        void setType(char);
        virtual void print();

        virtual Article* clone() =0;
        Article() =default;
        Article(std::string name, std::string manufacturer,
        int stock, int diameter, float price);
        virtual ~Article();
        friend std::ostream& operator<<(std::ostream& output, Article& a);
        friend std::istream& operator>>(std::istream& input, Article& a);

        virtual std::stringstream exp() = 0;
        virtual void loadData(std::istream&) =0;

        
    protected:
        std::string name;
        std::string manufacturer;
        int stock;
        int diameter;
        float price;
        char type;
};