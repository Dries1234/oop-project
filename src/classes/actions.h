#pragma once
#include "tireCenter.h"
#include "tire.h"
#include "rim.h"
#include "article.h"

void addArticle(TireCenter&, Article*);
void deleteArticle(TireCenter, int);
void changeArticle(TireCenter, int);
void checkInvoices(TireCenter);
void addCustomer(TireCenter);
void deleteCustomer(TireCenter);
void changeCustomer(TireCenter);
Article* createArticle();
Article* searchArticle();
