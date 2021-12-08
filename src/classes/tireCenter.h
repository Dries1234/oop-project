#pragma once
#include <string>
#include <vector>
#include <map>
#include "article.h"
#include "customer.h"

enum class Perms {
    A_ADD,
    A_REMOVE,
    A_CHANGE,
    A_SEARCH,

    I_CHECK,

    C_DELETE,
    C_CHANGE,
    C_ADD,

    O_PLACE,

    LENGTH //length of enum
};

const std::map<Perms, std::string> permDescription{

    {Perms::A_ADD, "Add article"},
    {Perms::A_REMOVE, "Remove article"},
    {Perms::A_CHANGE, "Change article"},
    {Perms::A_SEARCH, "Search article"},
    {Perms::I_CHECK, "Check invoices"},
    {Perms::C_ADD, "Add customer"},
    {Perms::C_CHANGE, "Change customer"},
    {Perms::C_DELETE, "Delete customer"},
    {Perms::O_PLACE, "Place order"},
};

enum class Functions{
    OWNER,
    EMPLOYEE
};

const std::vector<Perms> permissionVector[]{
       //owner
    {Perms::A_ADD, Perms::A_REMOVE, Perms::A_CHANGE, Perms::A_SEARCH, 
    Perms::I_CHECK, Perms::C_DELETE, Perms::C_CHANGE, 
    Perms::C_ADD, Perms::O_PLACE},
    //employee
    {Perms::A_CHANGE, Perms::I_CHECK, Perms::O_PLACE, Perms::C_CHANGE, Perms::C_ADD}
};

class TireCenter{
    public:
        std::string getName();
        void setName(std::string);

        std::string getAddress();
        void setAddress(std::string);

        std::vector<Article*>& getArticles();
        void addArticle(Article*);

        std::vector<Customer*>& getCustomers();
        void addCustomer(Customer);

        TireCenter();
        ~TireCenter();

    private:
        std::string name;
        std::string address;
        std::vector<Article*> articles;
        std::vector<Customer*> customers;

};

