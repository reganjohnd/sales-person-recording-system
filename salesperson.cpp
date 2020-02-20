using namespace std;

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdio.h>
#include "stdlib.h"

#include "mainmenu.h"
#include "salesperson.h"
#include "variables.h"
#include "sales.h"

static vector<salesperson> spv;

salesperson::salesperson(): id(0)
{}

salesperson::salesperson(string name, int id)
	:name{ name }, id{ id }
{}

salesperson::~salesperson() {}

ostream& operator << (ostream& os, const salesperson& p)
{
	os << p.name << "," << p.id << endl;
	return os;
}
istream& operator>> (istream& is, salesperson& p)
{
	is >> p.name >> p.id;
	return is;
}

void getlines(string& s)
{
	cin.ignore();
	getline(cin, s);
}

void salesperson::addSalesPerson()
{
	system("CLS");
	string s;
	long int i{};
	ofstream salespersons;
	
	cout << "Name: ";
	getlines(s);
	 
	cout << "ID: ";
	cin >> i;

	salesperson x{s, i};

	salespersons.open("C:/Users/Roger/Documents/salespersons.txt", ios::app | ios::out);
	if (!salespersons.is_open())
	{
		cout<<"File not found!"<<endl;
	}
	else
	{
		salespersons << i << "," << s << endl;
		salespersons.close();
	}

	spv.push_back({ s, i });
}

void salesperson::viewSalesPersons()
{
	for (int i = 0; i < spv.size(); i++)
	{
		cout << spv[i].name << "," << spv[i].id << endl;
	}
}
void salesperson::addSale()
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
		for (int i = 0; i < spv.size(); i++)
		{
			if (id == spv[i].id)
			{
				salesFigures << spv[i].name;
			}
		};
		salesFigures << "," << qty << "," << sales.get_value(qty) << endl;
		salesFigures.close();
	}
}