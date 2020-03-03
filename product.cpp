#include "product.h"
#include <iostream>


product::product():product_id(0), product_cPrice(0), product_sPrice(0)
{}

product::product(int product_id)
	:product_id{product_id}
{}

product::product(bool product_status, int product_id, string product_name, double product_cPrice, double product_sPrice)
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