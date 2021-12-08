#include "classes/tireCenter.h"
#include <string>
#include <vector>



std::string TireCenter::getName(){return name;}
void TireCenter::setName(std::string n){name = n;}

std::string TireCenter::getAddress(){return address;}
void TireCenter::setAddress(std::string a){address = a;}

std::vector<Article*>& TireCenter::getArticles(){return articles;}
void TireCenter::addArticle(Article *art){articles.push_back(art);}

std::vector<Customer*>& TireCenter::getCustomers(){return customers;}
void TireCenter::addCustomer(Customer cust){customers.push_back(&cust);}

TireCenter::TireCenter() 
{
    
}

TireCenter::~TireCenter() 
{
    
}

