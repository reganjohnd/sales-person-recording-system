#pragma once

class salesperson
{
public:
	std::string sp_name, sp_id;

	salesperson();
	salesperson(std::string sp_id);
	salesperson(std::string sp_name, std::string sp_id);
	~salesperson();

	static void addSalesPerson();
	static void addSale();
	static void deleteSalesPerson();

	static void view_salespersons();
	static int count();
};