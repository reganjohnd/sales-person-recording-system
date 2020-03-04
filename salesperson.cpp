using namespace std;


#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "stdlib.h"
#include <sstream>
#include <iostream>

#include "salesperson.h"
#include "product.h"
#include "sales.h"
#include "mainmenu.h"

//default constructor
salesperson::salesperson()
{}

salesperson::salesperson(string sp_id)
	:sp_id{sp_id}
{}

salesperson::salesperson(string sp_name, string sp_id)
	:sp_name{ sp_name }, sp_id{ sp_id }
{}

salesperson::~salesperson() {}

//enable cout for salsperson class
ostream& operator << (ostream& os, const salesperson& p)
{
	os << p.sp_name << "," << p.sp_id << endl;
	return os;
}

//enable cin for salesperson class
istream& operator>> (istream& is, salesperson& p)
{
	is >> p.sp_name >> p.sp_id;
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

		if (salespersons.good())
			cout << "Sales person added successfully!" << endl;
		else
			cout << "Error! Sales person could not be added" << endl;

		salespersons.close();
	}
}

void salesperson::deleteSalesPerson()
{
	system("CLS");
	ifstream input;
	ofstream output;

	input.open("C:/Users/Roger/Documents/salepersons.txt");

	string tmp_id, tmp_name;
	vector<string> v_id, v_name;

	for(int i = 0; i < count(); i++)
	{
		getline(input, tmp_id, ',');
		getline(input, tmp_name, '\n');
		v_id.push_back(tmp_id);
		v_name.push_back(tmp_name);
	}

	cout << "Employee ID: ";
	getline(cin, tmp_id);

	output.open("C:Users/Roger/Documents/temp.txt");

	for (int i = 0; i < count(); i++)
	{
		if (tmp_id != v_id[i])
			output << v_id[i] << "," << v_name[i] << endl;
	}
	input.close();
	output.close();

	remove("C:/Users/Roger/Documents/salepersons.txt");
	int result{ rename("C:Users/Roger/Documents/temp.txt", "C:/Users/Roger/Documents/salepersons.txt") };
}

//add sale for specific sales person to file 
void salesperson::addSale()
{
	system("CLS");
	ofstream salesFigures;
	ifstream input;

	string id, product_id;
	string* pid{ &id };
	int qty{};
	int* pqty{ &qty };
	int count{};
	int* pcount{ &count };
	string date;
	vector<string> vsp_id;
	vector<string> vsp_name; 
	string line;

	cout << "Date: ";
	cin.ignore();
	getline(cin, date);

	cout << "Employee ID: ";
	getline(cin, id);

	input.open("C:/Users/Roger/Documents/salespersons.txt");
	if (!input)
		cerr << "Cannot open file" << endl;
	input.clear();
	input.seekg(ios::beg);
	
	input.ignore(500, '\n');

	string sp_id;
	string sp_name;
	salesperson sp("", "");
	for (int i = 0; i < salesperson::count(); i++)
	{
		getline(input, sp_id, ',');
		getline(input, sp_name, '\n');
		vsp_id.push_back(sp_id);
		vsp_name.push_back(sp_name);

		if (sp_id == id)
		{
			cout << "success"<<endl;
			sp.sp_id = sp_id;
			sp.sp_name = sp_name;
		}
	}
	input.close();

	cout << "Product ID: ";
	getline(cin, product_id);

	string p_name, p_id, p_status, p_cpr, p_spr;
	vector<string> vp_status, vp_id, vp_name, vp_cpr, vp_spr;
	product p(true, "", "", 0.00, 0.00);
	input.open("C:/Users/Roger/Documents/products.txt");
	if (!input)
		cerr << "Cannot open file" << endl;
	input.ignore(500, '\n');

	for (int i = 0; i < product::p_count(); i++)
	{
		getline(input, p_status, ',');
		getline(input, p_id, ',');
		getline(input, p_name, ',');
		getline(input, p_cpr, ',');
		getline(input, p_spr, '\n');

		vp_status.push_back(p_status);
		vp_id.push_back(p_id);
		vp_name.push_back(p_name);
		vp_cpr.push_back(p_cpr);
		vp_spr.push_back(p_spr);

		if (p_id == product_id)
		{
			if (p_status == "0")
			{
				cerr << "This product is no longer available!" << endl<<endl;
				system("pause");
				mainmenu::mainMenu();
			}
			else if (p_status == "1")
			{
				istringstream(p_status) >> p.product_status;
				p.product_id = p_id;
				p.product_name = p_name;
				p.product_cPrice = stod(p_cpr);
				p.product_sPrice = stod(p_spr);
			}
		}
	}

	cout << "quantity: ";
	cin >> qty;
	
	sales sales(sp.sp_id, p.product_id, qty, date, p.product_sPrice);

	salesFigures.open("C:/Users/Roger/Documents/salesfigures.txt", ios::app);
	if (!salesFigures.is_open())
		cout << "File Not Found!";
	else
	{
		salesFigures << date << ",";

		/*vector<int> spID_{};
		int o{};
		string z;
			for (int i = 0; i < salesperson::count(); i++)
			{
				z = spID[i];
				o = stoi(z);
				spID_.push_back(o);
			}*/

		for (int i = 0; i < salesperson::count(); i++)
		{
			if (id == vsp_id[i])//matching inputted id with ids in file to match with the relevant name 
			{
				salesFigures << vsp_name[i] << ","; //and then output that name into salesfigures.txt file
				break;
			}
		}
		for (int i = 0; i < product::p_count(); i++)
		{
			if (product_id == vp_id[i])
			{
				salesFigures << vp_name[i] << ",";
				break;
			}
		}
		salesFigures << *pqty << "," << sales.get_value(qty) << endl;
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