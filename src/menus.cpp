#include <iostream>
#include "classes/menus.h"
#include "classes/tireCenter.h"
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