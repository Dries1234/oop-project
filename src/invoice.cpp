#include "classes/invoice.h"

Customer Invoice::getCustomer() 
{
    return customer;
}

void Invoice::setCustomer(Customer c) 
{
    customer = c;
}

std::vector<Article *> Invoice::getArticles() 
{
    return articles;
}

void Invoice::setArticles(std::vector<Article*> a) 
{
    articles = a;
}

float Invoice::getPrice() 
{
    return price;
}

void Invoice::setPrice(float p) 
{
    price = p;
}

int Invoice::getDiscount() 
{
    return discount;
}

void Invoice::setDiscount(int d) 
{
    discount = d;
}

Invoice::Invoice() 
{
    
}

Invoice::~Invoice() 
{
    
}
