#include <iostream>
#include "classes/tireCenter.h"
#include "classes/menus.h"
#include "classes/actions.h"
int main(){

    Menus menus;
    Perms action = menus.drawActionMenus(permissionVector[(int)menus.loginMenu()]);
    TireCenter tireCenter;
    switch(action){
        case Perms::A_ADD:
            menus.addArticleMenu(tireCenter);
            break;
        case Perms::A_REMOVE:
            
            break;
    }
    return 0;
}