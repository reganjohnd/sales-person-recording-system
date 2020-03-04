#pragma once
using namespace std;
#include <string>

class product
{
public:
	string product_name;
	string product_id;
	bool product_status;
	double product_cPrice, product_sPrice;

	product();
	product(string product_id, double product_sPrice);
	product(bool product_status, string product_id, string product_name, double product_cPrice, double product_sPrice);
	~product();

	static int p_count();
};

