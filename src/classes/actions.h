#pragma once
#include "tireCenter.h"
#include "tire.h"
#include "rim.h"
#include "article.h"
#include "menus.h"
#include "invoice.h"

void addArticle(TireCenter&, Article*);
void deleteArticle(TireCenter&);
void changeArticle(TireCenter&);
void placeOrder(TireCenter&);
void checkInvoices(TireCenter&);
void addCustomer(TireCenter&, Customer*);
void deleteCustomer(TireCenter&);
void changeCustomer(TireCenter&);
Article* createArticle();
Invoice* createInvoice(TireCenter&, std::vector<Article*>);
int searchArticle(TireCenter&,bool);
int searchCustomer(TireCenter&, bool);
Customer* createCustomer();
