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

#include "sales.h"

//default constructor
sales::sales()
{}

sales::sales(int sp_id, int product_id, int qty, string date)
	:salesperson{ sp_id }, product{ product_id }, qty{ qty }, date{ date }
{}

sales::~sales(){}

//returns sum of all sales
int sales::get_value(int& x)
{
	return x * product_sPrice;
}