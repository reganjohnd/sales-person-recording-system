#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>


#include "mainmenu.h"

class salesperson
{
public:
	string sp_name;
	int sp_id;

	salesperson();
	salesperson(int sp_id);
	salesperson(string name, int sp_id);
	~salesperson();

	static void addSalesPerson();
	static void addSale();

	static void view_salespersons();
	static int count();
};