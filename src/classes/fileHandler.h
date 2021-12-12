#pragma once
#include "tireCenter.h"
class FileHandler{
    public:
        void saveData(TireCenter&);
        void loadData(TireCenter&);

        void loadArticle(std::istream&);

        FileHandler();
        ~FileHandler();
};

