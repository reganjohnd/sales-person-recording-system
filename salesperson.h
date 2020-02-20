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
	string name;
	int id;
	//static vector<salesperson> spv;

	salesperson();
	salesperson(string name, int id);
	~salesperson();

	static void addSalesPerson();
	static void viewSalesPersons();
	static void addSale();
};