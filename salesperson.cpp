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

//default constructor
salesperson::salesperson(): id(0)
{}

salesperson::salesperson(string name, int id)
	:name{ name }, id{ id }
{}

salesperson::~salesperson() {}

//enable cout for salsperson class
ostream& operator << (ostream& os, const salesperson& p)
{
	os << p.name << "," << p.id << endl;
	return os;
}

//enable cin for salesperson class
istream& operator>> (istream& is, salesperson& p)
{
	is >> p.name >> p.id;
	return is;
}

//incorporate cin.ignore in the getline function 
void getlines(string& s)
{
	cin.ignore();
	getline(cin, s);
}

//add new salesperson to the sale person .txt file
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



//add sale for specific sales person to file 
void salesperson::addSale()
{
	system("CLS");
	ofstream salesFigures;
	ifstream input;

	int id{};
	int* pid{ &id };
	int qty{};
	int* pqty{ &qty };
	int count{};
	int* pcount{ &count };
	string date;
	vector<string> spID;
	vector<string> name; 
	string line;

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
	count--;

	input.clear(); //because previous 'while' statement reached the eof(), seekg will not work until file is cleared
	input.seekg(ios::beg);
	input.ignore(500, '\n');

	string x{};
	string y{};
	for (int i = 0; i < count; i++)
	{
		getline(input, x, ',');
		getline(input, y, '\n');
		spID.push_back(x);
		name.push_back(y);
	}
	input.close();

	salesFigures.open("C:/Users/Roger/Documents/salesfigures.txt", ios::app);
	if (!salesFigures.is_open())
		cout << "File Not Found!";
	else
	{
		salesFigures << date << ",";

		vector<int> spID_{};
		int o{};
		string z;
			for (int i = 0; i < count; i++)
			{
				z = spID[i];
				o = stoi(z);
				spID_.push_back(o);
			}

		for (int i = 0; i < count; i++)
		{
			if(id == spID_[i]) //matching inputted id with ids in file to match with the relevant name 
			{
				salesFigures << name[i]; //and then output that name into salesfigures.txt file
			}
		}
		salesFigures << "," << *pqty << "," << sales.get_value(qty) << endl;
		salesFigures.close();
	}
}

int salesperson::count()
{
	string line;
	int c{};
	ifstream input;
	input.open("C:/Users/Roger/Documents/salespersons.txt");

	while (getline(input, line))
	{
		c++;
	}
	//c--;
	return c;
}

//display sales persons currently on file
void salesperson::view_salespersons()
{
	system("CLS");

	ifstream input;
	input.open("C:/Users/Roger/Documents/salespersons.txt");

	string name, id;

	for (int i = 0; i < count(); i++)
	{
		getline(input, id, ',');
		getline(input, name, '\n');

		cout << id << "\t\t\t\t" << name << endl;
	}
	input.close();
	system("pause");
} 