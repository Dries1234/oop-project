#pragma once
#include "customer.h"
#include "article.h"
#include <vector>
class Invoice{
    public:
        Customer getCustomer();
        void setCustomer(Customer);

        std::vector<Article*> getArticles();
        void setArticles(std::vector<Article*>);

        float getPrice();
        void setPrice(float);

        int getDiscount();
        void setDiscount(int);

        Invoice();
        ~Invoice();

    private:
        Customer customer;
        std::vector<Article*> articles;
        float price;
        int discount;
};