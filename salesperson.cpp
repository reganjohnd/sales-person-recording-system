using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
	system("CLS");
	ofstream salesFigures;
	ifstream input;

	int id{};
	int* pid{ &id };

	int qty{};
	int* pqty{ &qty };

	string date;
//	string* pdate{ &date };

	string spID[10];
//	string* pspID[10]{ &spID[10] };

	string name[10]; 
	//string* pname[10]{ &name[10] };

	string line;
	//string* pline{ &line };

	int count{};
	int* pcount{ &count };

	cout << "Date: ";
	cin.ignore();
	getline(cin, date);
	cout << "ID: ";
	cin >> id;
	cout << "quantity: ";
	cin >> qty;
	sales sales(id, qty, date);
	
	input.open("C:/Users/Roger/Documents/salespersons.txt");
	input.ignore(500, '\n');
	
	while (input)
	{
		getline(input, line);
		count++;
	}

	input.clear(); //because previous 'while' statement reached the eof(), seekg will not work until file is cleared
	input.seekg(1, ios::beg);
	input.ignore(500, '\n');

	for (int i = 0; i < count; i++)
	{
		getline(input, spID[i], ',');
		getline(input, name[i], '\n');
	}

	input.close();

	salesFigures.open("C:/Users/Roger/Documents/salesfigures.txt", ios::app);
	if (!salesFigures.is_open())
	{
		cout << "File Not Found!";
	}
	else
	{
		salesFigures << date << ",";

		int spID_[10]{};
			for (int i = 0; i < count; i++)
			{
				spID_[i] = atoi(spID[i].c_str());
			}
			
			//cout << id << spID_[0];
			//system("pause");

		for (int i = 0; i < count; i++)
		{
			if(id == spID_[i])
			{
				salesFigures << name[i];
			}
		}
		salesFigures << "," << *pqty << "," << sales.get_value(qty) << endl;
		salesFigures.close();
	}

	/*salesFigures.open("C:/Users/Roger/Documents/salesfigures.txt", ios::app | ios::out);
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
	}*/
}

/*int a{ 1 };
int b{ 2 };
int c{ 3 };

int* pa{ &a };
int* pb{ &b };
int* pc{ &c };

int na{ *pa };
int nb{ *pb };
int nc{ *pc };

cout << a << *pa << na << endl;
	cout << b << *pb << nb << endl;
	cout << c << *pc << nc << endl;*/