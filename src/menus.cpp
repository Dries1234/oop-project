#include <iostream>
#include "classes/menus.h"
#include "classes/util.h"
#include <algorithm>

#include <vector>
#include <string>
#include <sstream>

Perms Menus::drawActionMenus(std::vector<Perms> permissions){
    unsigned int option;
    std::stringstream menu;
    std::cout << "======= Action Menu =======" << std::endl;
    do{
        for(unsigned int i = 0; i < permissions.size(); i++){
            menu << "" << i+1 << "." <<  permDescription.at(permissions[i]) << std::endl;
        }
        std::string menustring = menu.str();
        std::cout << menustring << std::endl;
        std::cout << "Pick one:";
        std::cin >> option;
        std::cout << std::endl;
    }while(!(option >= 1 && option <= permissions.size()));

    return permissions[option-1];

}

Functions Menus::loginMenu(){
    int option;

    do{
        std::cout << "======= Login menu =======" << std::endl
            << "\t1. Owner" << std::endl
            << "\t2. Employee" << std::endl;
        std::cout << "Pick one:";
        std::cin >> option;
        std::cout << std::endl;
    }while(!(option >= 1 && option <=2));

    return static_cast<Functions>(option-1); // returns enum
}

void Menus::addArticleMenu(TireCenter& t){
    Article* a = createArticle();
    addArticle(t,a);
}

void Menus::addCustomerMenu(TireCenter& t){
    Util util;
    Customer * c = createCustomer();
    for(auto cust : t.getCustomers()){
        if(util.asciiToLower(cust->getName()) == util.asciiToLower(c->getName())){
            std::cout << "Creating customer failed!" << std::endl << "That customer already exists!" << std::endl << std::endl;
            return;
        }
    }
    addCustomer(t, c);
}

Menus::Menus() 
{
    
}

Menus::~Menus() 
{
    
}
/**
 * Returns: An integer from 0-2
 *         0: Tire
 *         1: Rim
 *         2: Size
 **/
int Menus::searchArticleMenu(){
    int option;
    do {
        std::cout << "======= Search menu =======" << std::endl
        << "\t1. Tires" << std::endl
        << "\t2. Rims" << std::endl
        << "\t3. Size" << std::endl;
        std::cout << "Pick one: ";
        std::cin >> option;
    }while(!(option >= 1 && option <= 3));

    return (option-1);
}
/**
 * Returns: An integer from 0-2
 *         0: Private
 *         1: Company
 *      
 **/
int Menus::searchCustomerMenu(){
    int option;
     do{
        std::cout << "======= Search Customers =======" << std::endl
        << "\t1. Private" << std::endl
        << "\t2. Company" << std::endl;
        std::cin.ignore();
        std::cin >> option;
    }while(!(option >= 1 && option <=2));
    return(option-1);
}

