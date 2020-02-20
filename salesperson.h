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

	salesperson();
	salesperson(string name, int id);
	~salesperson();

	static void addSalesPerson();
};