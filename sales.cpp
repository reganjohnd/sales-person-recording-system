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

sales::sales()
{}

sales::sales(int id, int qty, string date)
	:id{ id }, qty{ qty }, date{date}
{}

sales::~sales(){}

int sales::get_value(int& x)
{
	return x * 22;
}

/*void sales::addSale()
{
	ofstream salesFigures;
	ifstream salesPeople;
	int id{}, qty{};
	string date;

	cout << "Date: ";
	cin.ignore();
	getline(cin, date);
	cout << "ID: ";
	cin >> id;
	cout << "quantity: ";
	cin >> qty;

	sales sales(id, qty, date);

	salesFigures.open("C:/Users/Roger/Documents/salesfigures.txt", ios::app | ios::out);
	if (!salesFigures.is_open())
	{
		cout << "File not found!" << endl;
	}
	else
	{
		salesFigures << date << ",";
		for (int i = 0; i < salesperson::spv.size(); i++)
		{
				if (id == salesperson::spv[i].id)
				{
					cout << salesperson::spv[i].name;
				}
		};
		cout << "," << qty << "," << sales.get_value(qty) << endl;
		salesFigures.close();
	}
}*/

