#include <iostream>
#include <string>

#include "salesperson.h"
#include "sales.h"

//default constructor
sales::sales()
{}

sales::sales(string sp_id, string product_id, int qty, string date, double product_sPrice)
	:salesperson{ sp_id }, product{ product_id, product_sPrice }, qty{ qty }, date{ date }
{}

sales::~sales(){}

//returns sum of all sales
double sales::get_value(int& x)
{
	return x * product_sPrice;
}