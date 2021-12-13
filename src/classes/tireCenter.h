#pragma once
#include <string>
#include <vector>
#include <map>
#include "article.h"
#include "customer.h"
#include "invoice.h"
#include <fstream>

enum class Perms {
    A_ADD,
    A_REMOVE,
    A_CHANGE,
    A_SEARCH,

    I_CHECK,

    C_DELETE,
    C_CHANGE,
    C_ADD,
    C_SEARCH,

    O_PLACE,

    TC_UPDATE,
    P_QUIT
};

const std::map<Perms, std::string> permDescription{

    {Perms::A_ADD, "Add article"},
    {Perms::A_REMOVE, "Remove article"},
    {Perms::A_CHANGE, "Change article"},
    {Perms::A_SEARCH, "Search article"},
    {Perms::I_CHECK, "Check invoices"},
    {Perms::C_ADD, "Add customer"},
    {Perms::C_SEARCH, "Search a customer"},
    {Perms::C_CHANGE, "Change customer"},
    {Perms::C_DELETE, "Delete customer"},
    {Perms::O_PLACE, "Place order"},
    {Perms::TC_UPDATE, "Update TireCenter"},
    {Perms::P_QUIT, "Quit program"},
};

enum class Functions{
    OWNER,
    EMPLOYEE
};

const std::vector<Perms> permissionVector[]{
       //owner
    {Perms::A_ADD, Perms::A_SEARCH, Perms::A_CHANGE, Perms::A_REMOVE, 
    Perms::I_CHECK, Perms::C_ADD, Perms::C_SEARCH, 
    Perms::C_CHANGE, Perms::C_DELETE, Perms::O_PLACE, Perms::TC_UPDATE,Perms::P_QUIT},
    //employee
    {Perms::A_CHANGE, Perms::I_CHECK, Perms::O_PLACE, Perms::C_CHANGE, Perms::C_ADD, Perms::C_SEARCH, Perms::P_QUIT}
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
        void addCustomer(Customer*);

        std::vector<Invoice*>&getInvoices();
        void addInvoice(Invoice*);

        friend std::ostream& operator<<(std::ostream& output, TireCenter& tireCenter);
        friend std::istream& operator>>(std::istream& input, TireCenter& tireCenter);

        std::stringstream exp();
        
        void loadData(std::istream&);

        void update();
        TireCenter();
        ~TireCenter();


    private:
        std::string name;
        std::string address;
        std::vector<Article*> articles;
        std::vector<Customer*> customers;
        std::vector<Invoice*> invoices;

};

