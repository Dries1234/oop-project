#include "classes/fileHandler.h"
#include "classes/article.h"
#include "classes/tireCenter.h"
#include "classes/tire.h"
#include "classes/rim.h"
#include "classes/customer.h"
#include "classes/company.h"
#include <iostream>
void FileHandler::saveData(TireCenter& tireCenter) 
{
   saveArticles(tireCenter);
   saveCustomers(tireCenter);
   saveTireCenter(tireCenter);

}
void FileHandler::loadData(TireCenter& tireCenter) 
{
    loadArticles(tireCenter);
    loadCustomers(tireCenter);
    loadTireCenter(tireCenter);
}


void FileHandler::saveArticles(TireCenter& tireCenter){
    std::ofstream stream = outputFile("save/articles");
    stream << tireCenter.getArticles().size() << std::endl;
    for(auto article : tireCenter.getArticles()){
        stream << *article;
    }
    stream.close();
}

void FileHandler::saveCustomers(TireCenter& tireCenter){
    std::ofstream stream = outputFile("save/customers");
    stream << tireCenter.getCustomers().size() << std::endl;
    for(auto customer : tireCenter.getCustomers()){
        stream << *customer;
    }
    stream.close();
}

void FileHandler::saveTireCenter(TireCenter& tireCenter) 
{
    std::ofstream stream = outputFile("save/tirecenter");
    stream << tireCenter;
    stream.close(); 
}

void FileHandler::saveInvoices(TireCenter&) 
{
    
}

void FileHandler::loadArticles(TireCenter& tireCenter){
    std::ifstream stream = inputFile("save/articles");
    int n;
    std::string buffer;
    std::getline(stream,buffer);
    if(buffer == ""){ n = 0; }
    else { n = std::stoi(buffer); }
    Article* article;

    for(int i = 0; i < n; i++)
    {
        // get rid of type
        std::string type;
        std::getline(stream, type);
        if(type[0] == 't')
        {
            article = new Tire();
        }
        else if(type[0] == 'r')
        {
            article = new Rim();
        }
        stream >> *article;
        tireCenter.addArticle(article);
    }
    stream.close();
}

void FileHandler::loadCustomers(TireCenter& tireCenter){
    std::ifstream stream = inputFile("save/customers");
    int n;
    std::string buffer;
    std::getline(stream,buffer);
    if(buffer == ""){ n = 0; }
    else { n = std::stoi(buffer); }
    Customer* customer;

    for(int i = 0; i < n; i++)
    {
        // check for type
        std::string type;
        std::getline(stream, type);
        if(type[0] == 'c')
        {
            customer = new Company();
        }
        else if(type[0] == 'p')
        {
            customer = new Customer();
        }
        stream >> *customer;
        tireCenter.addCustomer(customer);
    }
    stream.close();

}

void FileHandler::loadTireCenter(TireCenter& tireCenter) 
{
    std::ifstream stream = inputFile("save/tirecenter");
    stream >> tireCenter;
    stream.close();
}

void FileHandler::loadInvoices(TireCenter&) 
{
    
}

std::ofstream FileHandler::outputFile(std::string path){
    std::ofstream stream{path, std::ios::out};
    if (!stream)
    {
        std::cerr << "The file: " << path << " cant't be opened!" << std::endl;
        exit(1);
    }
    return stream;
}
std::ifstream FileHandler::inputFile(std::string path){
    std::ifstream stream{path, std::ios::in};
    if (!stream)
    {
        std::cerr << "The file" << path << " can't be opened!";
        exit(EXIT_FAILURE);
    }
    return stream;
}




FileHandler::FileHandler() 
{
    
}

FileHandler::~FileHandler() 
{
    
}
