#pragma once
#include <string>

#include "salesperson.h"
#include "product.h"


class sales 
	: public product, public salesperson
{
public:
	int qty = 0;
	string date;
	
	sales();
	sales(string sp_id, string product_id, int qty, string date, double product_sPrice);
	~sales();

	double get_value(int& x);
	
};