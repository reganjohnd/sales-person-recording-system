using namespace std;

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

#include "variables.h"
#include "mainmenu.h"
#include "sales.h"
#include "functions.h"




void mainmenu::mainMenu()
{
	while (1)
	{
		int menuSelect{};
		cout << "1->Add Sales person\n2-> Add Sales Figure" << endl;
		cin >> menuSelect;
		switch (menuSelect)
		{
		case 1:
			salesperson::addSalesPerson();
			break;

		case 2:
			sales::addSale();
			break;
		}
	}
}