#include <iostream>
#include "classes/tireCenter.h"
#include "classes/menus.h"
#include "classes/actions.h"
int main(){
    Menus menus;
    TireCenter tireCenter;
    int user = (int)menus.loginMenu();
    while(true){
        Perms action = menus.drawActionMenus(permissionVector[user]);

        switch(action){
            case Perms::A_ADD:
                menus.addArticleMenu(tireCenter);
                break;
            case Perms::A_REMOVE:
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
                return 0;
                break;
        }
    }
    return 0;

}