#include "classes/fileHandler.h"
#include "classes/article.h"
#include "classes/tireCenter.h"
#include "classes/tire.h"
#include "classes/rim.h"
#include <iostream>
void FileHandler::saveData(TireCenter& tireCenter) 
{
    std::string path = "save/articles";
    std::ofstream stream{path, std::ios::out};
    if (!stream)
    {
        std::cerr << "The file: " << path << " cant't be opened!" << std::endl;
        exit(1);
    }

    stream << tireCenter.getArticles().size() << std::endl;
    for(auto article : tireCenter.getArticles()){
        stream << *article;
    }
    stream.close();
}

void FileHandler::loadData(TireCenter& tireCenter) 
{
    std::string path = "save/articles";
    std::ifstream stream{path, std::ios::in};
    if (!stream)
    {
        std::cerr << "The file" << path << " can't be opened!";
        exit(EXIT_FAILURE);
    }
    int n;
    std::string buffer;
    std::getline(stream,buffer);
    if(buffer == ""){ n = 0; }
    else { n = std::stoi(buffer); }
    Article* article;

    for(int i = 0; i < n; i++)
    {
        // get rid of type
        std::string type;
        std::getline(stream, type);
        if(type[0] == 't')
        {
            article = new Tire();
        }
        else if(type[0] == 'r')
        {
            article = new Rim();
        }
        stream >> *article;
        tireCenter.addArticle(article);
    }
    stream.close();


}



FileHandler::FileHandler() 
{
    
}

FileHandler::~FileHandler() 
{
    
}
