#include "classes/invoice.h"
#include "classes/company.h"
#include "classes/tire.h"
#include "classes/rim.h"
#include <map>
#include <iostream>
#include <sstream>

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

std::stringstream Invoice::exp() 
{
    std::stringstream out;
    out << *customer
    << price << std::endl
    << discount << std::endl
    << getArticles().size() << std::endl;

    for(auto article : getArticles()){
        out << *article;
    }
    return out;
}

void Invoice::loadData(std::istream& input) 
{
    std::string buffer;
    std::vector<Article*> articlevector;
    Customer* c;
    std::getline(input,buffer);
    if(buffer[0] == 'p'){
        c = new Customer();
    }
    else if(buffer[0] == 'c'){
        c = new Company();
    }
    input >> *c;
    float price;
    std::getline(input, buffer);
    price = std::stof(buffer);
    int discount;
    std::getline(input,buffer);
    discount = std::stoi(buffer);
    int n;
    std::getline(input, buffer);
    if(buffer == ""){n  = 0;}
    else{ n = std::stoi(buffer);}
    for(int i = 0; i < n; i++){
        Article* article;
        std::getline(input,buffer);
        if(buffer[0] == 't'){
            article = new Tire();
        }
        else if(buffer[0] == 'r'){
            article = new Rim();
        }
        input >> *article;
        articlevector.push_back(article);
    }
    setCustomer(c);
    setPrice(price);
    setDiscount(discount);
    setArticles(articlevector);
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

std::ostream& operator<<(std::ostream& output, Invoice& i) 
{
 std::string input = i.exp().str();

 return (output << input);   
}

std::istream& operator>>(std::istream& input, Invoice& i)
{
    i.loadData(input);
    return input;
}


Invoice::Invoice() 
{
    
}

Invoice::~Invoice() 
{
    
}
