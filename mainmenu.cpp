using namespace std;

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "conio.h"
#include <stdio.h>


#include "mainmenu.h"
#include "sales.h"
#include "salesperson.h"

void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

void mainmenu::mainMenu()
{
	while (1)
	{
		system("CLS");
		int menuSelect;
		gotoxy(10, 3);
		cout << "*************************************************************";
		gotoxy(10, 23);
		cout << "*************************************************************";
		gotoxy(35, 6);
		cout << "MAIN MENU";
		gotoxy(32, 7);
		cout << "~~~~~~~~~~~~~~~~";
		gotoxy(32, 10);
		cout << "1->Add Sales person";
		gotoxy(32, 12);
		cout << "2->Add Sales Figure" << endl;;
		cin >> menuSelect;
		
		switch (menuSelect)
		{
		case 1:
			salesperson::addSalesPerson();
			break;

		case 2:
			salesperson::addSale();
			break;
		case 3:
			salesperson::viewSalesPersons();
			break;
		}
	}
}
/*
cout
<< "*************************************************************";
gotoxy(10, 23);
cout
<< "*************************************************************";
gotoxy(32, 6);
cout << "E D I T M E N U";
gotoxy(32, 7);
cout << "~~~~~~~~~~~~~~~~";
gotoxy(32, 10);
cout << "1: ADD PRODUCTS";
gotoxy(32, 12);
cout << "2: MODIFY PRODUCTS";
gotoxy(32, 14);
cout << "3: DELETE PRODUCTS";
gotoxy(32, 16);
cout << "0: EXIT";
gotoxy(32, 19);
cout << "Enter Choice : ";
ch = _getche();*/