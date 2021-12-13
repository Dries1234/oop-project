#pragma once
#include "tireCenter.h"
class FileHandler{
    public:
        void saveData(TireCenter&);
        void loadData(TireCenter&);

        std::ifstream inputFile(std::string);
        std::ofstream outputFile(std::string);

        void saveArticles(TireCenter&);
        void saveCustomers(TireCenter&);
        void saveTireCenter(TireCenter&);
        void saveInvoices(TireCenter&);

        void loadArticles(TireCenter&);
        void loadCustomers(TireCenter&);
        void loadTireCenter(TireCenter&);
        void loadInvoices(TireCenter&);


        FileHandler();
        ~FileHandler();
};

