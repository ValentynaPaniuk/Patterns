#include <iostream>
#include<fstream>
#include<string>
#include <map>

using namespace std;
/*
Створити класи Клієнт, Банк, Рахунок(номер рахунку, пароль, сума). 
У класі Рахунок визначити методи:
* отримання інформації про кошти на рахунку та 
* зняття з рахунку певної суми.

Створити клас Банкомат, який надаватиме сервіси зняття грошей та інформації по
рахунку певному клієнту. Використати патерн Proxy.

*/


class Bank
{
public:

	virtual void ShowInfo() = 0;
	virtual void Withdrawals() = 0;
	virtual ~Bank() {};
};


class Account : public Bank
{
	public:

		Account()
		{

		};
		virtual void ShowInfo()
		{
			cout << "Information about funds in the account ";
		}
		virtual void Withdrawals()
		{
			cout << "Cash withdrawal ";
		}

};


class ATM : public Bank
{
	string UserName;
	string Pwd;
	int number;
		
	Account account;

	bool ISAuthenticated()
	{
		bool bAuthenticated = false;
		return bAuthenticated;
	}
	
public:
	
	ATM(string sUserName, string sPwd, int sNumber ): UserName(), Pwd(sPwd), number(sNumber)
	{
	};

	virtual void ShowInfo()
	{
		if (ISAuthenticated())
		{
			cout << "\nAuthentication Success ";
			account.ShowInfo();
		}
		else
		{
			cout << "\nAuthentication Failure, You can't open the Account" << endl;
		}
	}

	virtual void Withdrawals()
	{
		if (ISAuthenticated())
		{
			cout << "Cash withdrawal ";
		}
		else
		{
			cout << "\nAuthentication Failure, You can't withdrawal money" << endl;
		}

	}

	~ATM()
	{
	};
};


int main()
{

	Bank *account = new ATM("Ivanov", "123", 123456);
	account->ShowInfo();
	account->Withdrawals();


	system("pause");
	return 0;
}
