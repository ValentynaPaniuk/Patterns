#include <iostream>
#include <string>
#include "Coffemachine.h"
#include "American.h"
#include "Americanwithmilk.h"
#include "Espresso.h"
#include "Espressowithmilk.h"
#include "Latte.h"
#include "Mocachino.h"
#include <vector>


using namespace std;

/*Кавомашина. 
Маню: 
* Американо 
* Американо з молоком 
* Еспрессо 
* Еспрессо з молоком 
* Лате
* Мокачіно.*/


int main()
{
	vector <Coffemachine*> drink;
	int choice;
	while (true)
	{
		cout << " ***  COFFEMACHINE *** " << endl;
		cout << "1. American" << endl;
		cout << "2. American with milk" << endl;
		cout << "3. Espresso" << endl;
		cout << "4. Espresso with milk" << endl;
		cout << "5. Latte" << endl;
		cout << "6. Mocachino" << endl;
		cout << "0. Exit" << endl;
		cin >> choice;
		cout << "The drink is being prepared. Wait for the result ..." << endl;
		if (choice == 0)
		{
			break;
		}
		else if (choice == 1)
		{
			drink.push_back(new American);
		}
		else if (choice == 2)
		{
			drink.push_back(new Americanwithmilk);
		}
		else if (choice == 3)
		{
			drink.push_back(new Espresso);
		}
		else if (choice == 4)
		{
			drink.push_back(new Espressowithmilk);
		}
		else if (choice == 5)
		{
			drink.push_back(new Latte);
		}
		else if (choice == 6)
		{
			drink.push_back(new Mocachino);
		}

	}

	cout << "=====	Coffee machine usage report ======" << endl;
	for (int i = 0; i < drink.size(); i++)
	{
		cout << "Drink N: " << i << " ";
		drink[i]->MakingCoffee();
	}
	cout << "=========================================" << endl;
	for (int i = 0; i < drink.size(); i++)
	{
		delete drink[i];
	}

		


	system("pause");
	return 0;
}