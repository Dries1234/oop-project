#include "classes/invoice.h"
#include "classes/company.h"
#include <map>
#include <iostream>

Customer* Invoice::getCustomer() 
{
    return customer;
}

void Invoice::setCustomer(Customer* c) 
{
    customer = c;
}

std::vector<Article *>& Invoice::getArticles() 
{
    return articles;
}

void Invoice::setArticles(std::vector<Article*>& a) 
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

float Invoice::calculateDiscount(){
    float percent = 10;
    int tires;
    std::map<int,int> tiremap;
    std::map<int,int> rimmap;
    float discountAmount = 0;
    for(auto &e : articles){
        if(e->getType() == 't')
        {
            tiremap[e->getDiameter()]+=1;
            tires++;
        }
        else if(e->getType() == 'r'){
            rimmap[e->getDiameter()]+=1;
        }
    }
    if(customer->getType() == 'p'){
        for(auto e : tiremap){
            if(e.second >= 4 && rimmap[e.first] >=4){
                discountAmount = calculatePrice() * (percent/(float)100);
            }
        }
    }
    else if(customer->getType() == 'c'){
        Company* comp = dynamic_cast<Company*>(customer); // cast to company to access volumeDiscount
        if(tires >= comp->getVolumeDiscount() * 4) // 10 sets of 4
        {
            discountAmount = calculatePrice() * (percent/ (float)100);
        }
    }
    
    return discountAmount;
}
float Invoice::calculatePrice(){
    float total;
    for(auto &e : articles){
        total += e->getPrice();
    }
    return total;
}

void Invoice::print(){
    std::cout << "+++++++++++++++++++++++ Invoice +++++++++++++++++++++++" <<std::endl;
    std::cout << "Customer: " << customer->getName() << std::endl;
    std::cout << "Articles: " << std::endl;
    int count = 1;
    for(auto &article : articles){
        std::cout  << "\t" << count << ": " << article->getName() << std::endl;
        count++;
    }
    std::cout << "Price: " << calculatePrice() << std::endl;
    std::cout << "Discount: " << calculateDiscount() << std::endl;
    std::cout << "Total: " << price << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
}

Invoice::Invoice() 
{
    
}

Invoice::~Invoice() 
{
    
}
