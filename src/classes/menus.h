#pragma once
#include <vector>
#include "tireCenter.h"
#include "actions.h"

class Menus {
    public:
        Perms drawActionMenus(std::vector<Perms> permissions);
        Functions loginMenu();
        void addArticleMenu(TireCenter& t);
        int searchArticleMenu();
        int searchCustomerMenu();
        void addCustomerMenu(TireCenter& t);

        Menus();
        ~Menus();
};