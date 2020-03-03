#pragma once
using namespace std;
#include <string>

class product
{
public:
	string product_name;
	int product_id;
	bool product_status;
	double product_cPrice, product_sPrice;

	product();
	product(int product_id);
	product(bool product_status, int product_id, string product_name, double product_cPrice, double product_sPrice);
	~product();

};

