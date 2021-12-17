#include "classes/actions.h"
#include "classes/article.h"
#include "classes/menus.h"
#include "classes/company.h"
#include "iostream"
#include <algorithm>
#include <map>

void addArticle(TireCenter &tireCenter, Article *article)
{
    tireCenter.addArticle(article);
}
void deleteArticle(TireCenter &tireCenter)
{
    auto &articles = tireCenter.getArticles();
    int index = searchArticle(tireCenter, true);
    if (index == -1)
    {
        return;
    }
    Article *a = articles[index];
    delete a;                                 // remove the pointer to avoid memory leaks
    articles.erase(articles.begin() + index); // erase the pointer from vector
}

void changeArticle(TireCenter &tireCenter)
{
    auto articles = tireCenter.getArticles();
    int index = searchArticle(tireCenter, true);
    if (index == -1)
    {
        return;
    }
    Article *article = articles.at(index);
    article->print();
    delete article;
    article = createArticle();
    articles[index] = article;
}

void placeOrder(TireCenter &tireCenter)
{
    int choice;
    std::vector<Article *> orderVector;
    auto articles = tireCenter.getArticles();
    Invoice *in;
    do
    {
        std::cout << "======= Order Menu =======" << std::endl
                  << "\t1. Add article to order" << std::endl
                  << "\t2. Finish order" << std::endl
                  << "\t3. Abort order" << std::endl;
        std::cin.ignore();
        std::cin >> choice;
        if (choice == 1)
        {
            int articleIndex = searchArticle(tireCenter, true);
            if (articleIndex == -1)
            {
                return;
            }
            int amount;
            std::cout << "How many times would you like to add this to the order: ";
            std::cin >> amount;
            if (articles[articleIndex]->getStock() < amount)
            {
                std::cout << "There is not enough stock to do that" << std::endl;
                return;
            }
            articles[articleIndex]->setStock(articles[articleIndex]->getStock() - amount); //update stock
            for (int i = 0; i < amount; i++)
            {
                orderVector.push_back(articles[articleIndex]->clone());
            }
        }
    } while (choice != 2 && choice != 3);
    switch(choice){
        case 2:
            in = createInvoice(tireCenter, orderVector);
            if (in == NULL)
            {
                return;
            }
            tireCenter.addInvoice(in);
            break;
        case 3:
            return;
            break;
    }

}

Invoice *createInvoice(TireCenter &tireCenter, std::vector<Article *> orderVector)
{
    std::cout << "Which customer is the order for?" << std::endl;
    int index = searchCustomer(tireCenter, true);
    if (index == -1)
    {
        return NULL;
    }
    Invoice *inv = new Invoice();
    auto customers = tireCenter.getCustomers();
    inv->setCustomer(customers[index]->clone());
    inv->setArticles(orderVector);
    float price = inv->calculatePrice();
    float discount = inv->calculateDiscount();
    float endPrice = price - discount;
    endPrice = endPrice * 1.21; // add BTW
    inv->setPrice(endPrice);
    inv->setDiscount(discount);

    return inv;
}
void checkInvoices(TireCenter &tireCenter)
{
    for (auto invoice : tireCenter.getInvoices())
    {
        invoice->print();
    }
}

void addCustomer(TireCenter &tireCenter, Customer *c)
{
    tireCenter.addCustomer(c);
}

void deleteCustomer(TireCenter &tireCenter)
{
    auto &customers = tireCenter.getCustomers();
    int index = searchCustomer(tireCenter, true);
    if (index == -1)
    {
        return;
    }
    Customer *c = customers[index];
    delete c;                                 // remove the pointer to avoid memory leaks
    customers.erase(customers.begin() + index); // erase the pointer from vector
}

void changeCustomer(TireCenter &tireCenter)
{
    auto customers = tireCenter.getCustomers();
    int index = searchCustomer(tireCenter, true);
    if (index == -1)
    {
        return;
    }
    Customer *customer = customers.at(index);
    customer->print();
    delete customer;
    customer = createCustomer();
    customers[index] = customer;
}


/**
 * @return the index of the customer in TireCenter or -1 if no customer
 * @param t The TireCenter class instance
 **/
int searchCustomer(TireCenter &tireCenter, bool choose)
{
    Menus menu;
    int option = menu.searchCustomerMenu();
    std::map<Customer *, int> filtered;
    for (size_t i = 0; i < tireCenter.getCustomers().size(); ++i)
    {
        auto &e = tireCenter.getCustomers()[i];
        switch (option)
        {
        case 0:
            if (e->getType() == 'p')
            {
                filtered[e] = i;
            }
            break;
        case 1:
            if (e->getType() == 'c')
            {
                filtered[e] = i;
            }
            break;
        }
    }

    if (filtered.size() < 1)
    {
        std::cout << "No results" << std::endl;
        return -1;
    }
    std::cout << "Search results: " << std::endl;
    int count = 1;
    for (auto &e : filtered)
    {
        std::cout << count << ":" << std::endl;
        e.first->print();
        count++;
    }
    if (choose)
    {
        unsigned int choice;
        std::cin.ignore();
        do
        {
            std::cout << "Which Customer would you like to choose (0 for none): ";
            std::cin >> choice;
        } while (!(choice <= filtered.size()));
        if (choice == 0)
        {
            return -1;
        }
        else
        {
            auto it = filtered.begin();
            std::advance(it, choice - 1);
            return it->second;
        }
    }
    else
    {
        return -1;
    }
}

Customer *createCustomer()
{
    std::cout << "======= Customer Creation =======" << std::endl;
    std::string name;
    std::string address;
    std::string buffer;
    std::string VAT;
    Customer *c;
    int volumeDiscount;
    char type;
    std::cin.ignore();
    do
    {
        std::cout << "Enter type of the Customer: ";
        std::getline(std::cin, buffer);
        type = buffer[0];
    } while (type != 'p' && type != 'c');
    std::cout << "What is the name of the customer: ";
    std::getline(std::cin, name);
    std::cout << "What is the address of the customer: ";
    std::getline(std::cin, address);
    if (type == 'c')
    {
        std::cout << "What is the Vat of the company: ";
        std::getline(std::cin, VAT);
        std::cout << "What is the volumeDiscount for the company: ";
        std::cin >> volumeDiscount;
        std::cin.ignore();
        c = new Company(name, address, type, VAT, volumeDiscount);
    }
    else
    {
        c = new Customer(name, address, type);
    }
    std::cout << std::endl;

    return c;
}

Article *createArticle()
{
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
    Article *a;
    std::cin.ignore();
    do
    {
        std::cout << "Enter type of the article: ";
        std::getline(std::cin, buffer);
        type = buffer[0];
    } while (type != 't' && type != 'r');
    std::string name;
    if (type == 't')
    {
        name = "tire";
    }
    else
    {
        name = "rim";
    }
    std::cout << "Enter a name for the " << name << ": ";
    std::getline(std::cin, articlename);
    std::cout << "Enter a manufacturer for the " << name << ": ";
    std::getline(std::cin, manufacturer);
    std::cout << "Enter stock for the " << name << ": ";
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
    switch (type)
    {
    case 't':
        std::cout << "Enter a height of the " << name << ": ";
        std::cin >> height;
        std::cin.ignore();
        std::cout << "Enter a speedIndex of the " << name << ": ";
        std::getline(std::cin, speedIndex);
        std::cout << "Enter a season of the " << name << ": ";
        std::getline(std::cin, buffer);
        season = buffer[0];
        a = new Tire(articlename, manufacturer, stock, diameter, price, width, height, speedIndex, season);
        break;
    case 'r':
        do{
            std::cout << "Is the Rim made of aluminium? yes(1) no(0): ";
            std::cin >> aluminium;
        }while(aluminium != 1 && aluminium != 0);
        std::cin.ignore();
        std::cout << "Enter a color of the " << name << ": ";
        std::getline(std::cin, color);
        a = new Rim(articlename, manufacturer, stock, diameter, price, width, aluminium, color);
        break;
    }
    return a;
}
/**
 * @return the index of the article in TireCenter or -1 if no article
 * @param t The TireCenter class instance
 **/
int searchArticle(TireCenter &t, bool choose)
{
    Menus menus;
    int option = menus.searchArticleMenu();
    int size;
    if (option == 2)
    {
        std::cout << "What diameter would you like to search for: " << std::endl;
        std::cin >> size;
    }
    std::map<Article *, int> filtered;
    auto articles = t.getArticles();
    for (size_t i = 0; i < articles.size(); ++i)
    {
        auto &e = articles[i];
        switch (option)
        {
        case 0:
            if (e->getType() == 't')
            {
                filtered[e] = i;
            }
            break;
        case 1:
            if (e->getType() == 'r')
            {
                filtered[e] = i;
            }
            break;
        case 2:

            if (e->getDiameter() == size)
            {
                filtered[e] = i;
            }
            break;
        }
    }

    if (filtered.size() < 1)
    {
        std::cout << "No results" << std::endl;
        return -1;
    }
    std::cout << "Search results: " << std::endl;
    int count = 1;
    for (auto &e : filtered)
    {
        std::cout << count << ":" << std::endl;
        e.first->print();
        count++;
    }
    if (choose)
    {
        unsigned int choice;
        do
        {
            std::cout << "Which article would you like to choose (0 for none): ";
            std::cin >> choice;
        } while (!(choice <= filtered.size()));
        if (choice == 0)
        {
            return -1;
        }
        else
        {
            auto it = filtered.begin();
            std::advance(it, choice - 1);
            return it->second;
        }
    }
    else
    {
        return -1;
    }
}