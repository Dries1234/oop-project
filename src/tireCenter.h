#pragma once
#include <string>
#include <vector>
#include "article.h"
#include "customer.h"
class TireCenter
{
public:
    std::string getName();
    void setName(std::string);

    std::string getAddress();
    void setAddress(std::string);

    std::vector<Article> getArticles();
    void setArticles(std::vector<Article>);

    std::vector<Customer> getCustomers();
    void setCustomers(std::vector<Customer>);

private:
    std::string name;
    std::string address;
    std::vector<Article> articles;
    std::vector<Customer> customers;
};