#pragma once
using namespace std;
#include <string>


#include "mainmenu.h"
#include "salesperson.h"
#include "product.h"


class sales 
	: public product, public salesperson
{
public:
	int qty = 0;
	string date;
	
	sales();
	sales(int sp_id, int product_id, int qty, string date);
	~sales();

	int get_value(int& x);
	
};