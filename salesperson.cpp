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

/*void getlines(string s)
{
	cin.ignore();
	getline(cin, s);
}*/

void salesperson::addSalesPerson()
{
	system("clr");
	string s;
	int i{};
	ofstream salespersons;
	cout << "Name: ";
	cin.ignore();
	getline(cin, s);


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
}
