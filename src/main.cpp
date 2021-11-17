#include <iostream>
#include "classes/tireCenter.h"
#include "classes/menus.h"
int main(){

    Menus menus;
    menus.drawActionMenus(permissionVector[(int)menus.loginMenu()]);
    
    return 0;
}