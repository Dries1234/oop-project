#include "classes/actions.h"
#include "iostream"
void addArticle(TireCenter &tireCenter, Article* article){
    tireCenter.addArticle(article);
}
void deleteArticle(TireCenter &tireCenter, int index){
    auto articles = tireCenter.getArticles();
    articles.erase(articles.begin() + index);
}

void changeArticle(TireCenter tireCenter, int index){
    auto articles = tireCenter.getArticles();
    Article* article = articles.at(index);
    article->print();
}

void checkInvoices(TireCenter){
    // do checking    
}

void addCustomer(TireCenter){
    // do adding
}

void deleteCustomer(TireCenter){
    // do deleting
}

void changeCustomer(TireCenter){
    // do changing
}

Article* createArticle(){
    std::cout << "======= Article Creation =======" << std::endl;
    char type;
    std::string articlename;
    std::string manufacturer;
    int stock;
    int diameter;
    float price;
    int width;
    int height;
    std::string speedIndex;
    char season;
    bool aluminium;
    std::string color;
    std::string buffer;
    Article* a;
    do{
        std::cout << "Enter type of the article: ";
        std::cin.ignore();
        std::getline(std::cin,buffer);
        type = buffer[0];
    }while(type != 't' && type != 'r');
    std::string name;
    if(type == 't'){
        name = "tire";
    }
    else{
        name = "rim";
    }
    std::cout << "Enter a name for the " << name << ": ";
    std::getline(std::cin, articlename);
    std::cout << "Enter a manufacturer for the " << name << ": ";
    std::getline(std::cin, manufacturer);
    std::cout << "Enter stock for the "  << name << ": ";
    std::cin >> stock;
    std::cin.ignore();
    std::cout << "Enter diameter of the " << name << ": ";
    std::cin >> diameter;
    std::cin.ignore();
    std::cout << "Enter price of the " << name << ": ";
    std::cin >> price;
    std::cin.ignore();
    std::cout << "Enter a width of the " << name << ": ";
    std::cin >> width;
    std::cin.ignore();
    switch(type){
        case  't':
                std::cout << "Enter a height of the " << name << ": ";
                std::cin >> height;
                std::cin.ignore();
                std::cout << "Enter a speedIndex of the " << name << ": ";
                std::getline(std::cin,speedIndex);
                std::cout << "Enter a season of the " << name << ": ";
                std::getline(std::cin, buffer);
                season = buffer[0];
                a = new Tire(articlename, manufacturer, stock, diameter,price,width,height,speedIndex,season);
            break;
        case 'r':
                std::cout << "Is the Rim made of aluminium? yes(1) no(0): ";
                std::cin >> aluminium;
                std::cin.ignore();
                std::cout << "Enter a color of the " << name << ": ";
                std::getline(std::cin, color);
                a = new Rim(articlename, manufacturer, stock, diameter,price,width,aluminium,color);
            break;
    }
    return a;
}