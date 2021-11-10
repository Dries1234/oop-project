#include "tireCenter.h"
#include <string>
#include <vector>

std::string TireCenter::getName(){return name;}
void TireCenter::setName(std::string n){name = n;}

std::string TireCenter::getAddress(){return address;}
void TireCenter::setAddress(std::string a){address = a;}

std::vector<Article> TireCenter::getArticles(){return articles;}
void TireCenter::setArticles(std::vector<Article> arts){articles = arts;}

std::vector<Customer> TireCenter::getCustomers(){return customers;}
void TireCenter::setCustomers(std::vector<Customer> custs){customers = custs;}

