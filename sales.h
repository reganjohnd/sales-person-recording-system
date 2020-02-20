#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdio.h>

#include "mainmenu.h"
#include "salesperson.h"


class sales 
{
public:
	int qty = 0;
	int id = 0;
	string date;

	sales();
	sales(int id, int qty, string date);
	~sales();

	static void addSale();
	int get_value(int x);
	
};