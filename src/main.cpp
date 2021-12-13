#include <iostream>
#include "classes/tireCenter.h"
#include "classes/menus.h"
#include "classes/actions.h"
#include "classes/fileHandler.h"
int main(){
    FileHandler fh;
    Menus menus;
    TireCenter tireCenter;

    fh.loadData(tireCenter);

    std::cout << R"(  _______ _           _____           _            
 |__   __(_)         / ____|         | |           
    | |   _ _ __ ___| |     ___ _ __ | |_ ___ _ __ 
    | |  | | '__/ _ \ |    / _ \ '_ \| __/ _ \ '__|
    | |  | | | |  __/ |___|  __/ | | | ||  __/ |   
    |_|  |_|_|  \___|\_____\___|_| |_|\__\___|_|   
                                                   
                                                   
)" << std::endl; 
    int user = (int)menus.loginMenu();
    bool running = true;

    
    while(running){
        Perms action = menus.drawActionMenus(permissionVector[user]);

        switch(action){
            case Perms::A_ADD:
                menus.addArticleMenu(tireCenter);
                break;
            case Perms::A_DELETE:
                deleteArticle(tireCenter);
                break;
            case Perms::A_CHANGE:
                changeArticle(tireCenter);
                break;
            case Perms::A_SEARCH:
                searchArticle(tireCenter, false);
                break;
            case Perms::I_CHECK:
                checkInvoices(tireCenter);
                break;
            case Perms::C_ADD:
                menus.addCustomerMenu(tireCenter);
                break;
            case Perms::C_DELETE:
                deleteCustomer(tireCenter);
                break;
            case Perms::C_CHANGE:
                changeCustomer(tireCenter);
                break;
            case Perms::C_SEARCH:
                searchCustomer(tireCenter, false);
                break;
            case Perms::O_PLACE:
                placeOrder(tireCenter);
                break;
            case Perms::TC_UPDATE:
                tireCenter.update();
                break;
            case Perms::P_QUIT:
                running = false;
                break;
        }
    }
    fh.saveData(tireCenter);
    return 0;

}