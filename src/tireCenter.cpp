#include "classes/tireCenter.h"
#include <string>
#include <vector>
#include <iostream>



std::string TireCenter::getName(){return name;}
void TireCenter::setName(std::string n){name = n;}

std::string TireCenter::getAddress(){return address;}
void TireCenter::setAddress(std::string a){address = a;}

std::vector<Article*>& TireCenter::getArticles(){return articles;}
void TireCenter::addArticle(Article *art){articles.push_back(art);}

std::vector<Customer*>& TireCenter::getCustomers(){return customers;}
void TireCenter::addCustomer(Customer* cust){customers.push_back(cust);}

std::vector<Invoice*>& TireCenter::getInvoices(){return invoices;}
void TireCenter::addInvoice(Invoice* inv){invoices.push_back(inv);}

void TireCenter::update(){
    std::string name;
    std::string address;
    std::cin.ignore();
    std::cout << "What is the name of this TireCenter: ";
    std::getline(std::cin, name);
    std::cout << "What is the address of this TireCenter: ";
    std::getline(std::cin, address);
    
}

TireCenter::TireCenter() 
{
    
}

TireCenter::~TireCenter() 
{
    
}

