using namespace std;
#include <iostream>
#include <string>
#include "salesperson.h"
#include "mainmenu.h"

//function to aid interface design
void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

//main menu from which to select options
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
		cout << "1 -> Add Sales person";
		gotoxy(32, 12);
		cout << "2 -> Add Sales Figure" << endl;;
		gotoxy(32, 14);
		cout << "3 -> View Sales persons";
		gotoxy(32, 16);
		cout << " 4 - > Delete Sales person";
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
			salesperson::view_salespersons();
			break;

		case 4:
			salesperson::deleteSalesPerson();
			break;
		}
	}
}