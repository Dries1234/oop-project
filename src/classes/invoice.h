#pragma once
#include "customer.h"
#include "article.h"
#include <vector>
class Invoice{
    public:
        Customer* getCustomer();
        void setCustomer(Customer*);

        std::vector<Article*>& getArticles();
        void setArticles(std::vector<Article*>&);

        float getPrice();
        void setPrice(float);

        int getDiscount();
        void setDiscount(int);

        float calculateDiscount();
        float calculatePrice();

        friend std::ostream& operator<<(std::ostream& output, Invoice& i);
        friend std::istream& operator>>(std::istream& input, Invoice& i);

        virtual std::stringstream exp();
        virtual void loadData(std::istream&);
        
        void print();
        Invoice();
        ~Invoice();

    private:
        Customer* customer;
        std::vector<Article*> articles;
        float price;
        int discount;
};