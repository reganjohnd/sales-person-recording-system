#include "product.h"
#include <iostream>
#include <fstream>


product::product():product_cPrice(0), product_sPrice(0), product_status(0)
{}

product::product(string product_id, double product_sPrice)
	: product_id{ product_id }, product_sPrice{ product_sPrice }, product_cPrice(0), product_status(0)
{}

product::product(bool product_status, string product_id, string product_name, double product_cPrice, double product_sPrice)
	: product_status{ product_status }, product_id{ product_id }, product_name{ product_name }, product_cPrice{ product_cPrice }, product_sPrice{ product_sPrice }
{}

product::~product()
	{}

istream& operator>> (istream& is, product& p)
{
	is >> p.product_name >> p.product_id >> p.product_status;
	return is;
}

ostream& operator << (ostream& os, const product& p)
{
	os << p.product_name << "," << p.product_id << endl;
	return os;
}

int product::p_count()
{
	string line;
	int c{};
	ifstream input;
	input.open("C:/Users/Roger/Documents/products.txt");

	while (getline(input, line))
	{
		c++;
	}
	c--;
	return c;
}