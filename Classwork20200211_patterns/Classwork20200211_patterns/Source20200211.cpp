#include <iostream>
#include<string>

using namespace std;

class President
{
	string name;
	string birthday;
	static President *instance;

	// Default Constructor
	President() {};
	~President()
	{	cout << "Default destructor: " << this << endl; };

	//Constructor copii
	President(President &other)
	{
		this->name = other.name;
		this->birthday = other.birthday;
		this->instance = other.instance;
	}


public:
	
	//Overload constructor
	President(string name, string birthday)
	{ 
		if (!instance)
		{
			this->name = name;
			this->birthday = birthday;
			this->instance = 0;
			cout << "Default constructor: " << this << endl;
		}
		else
		{
			cout << "Pytannia yak peredaty poperedne znachennia" << endl;
		}

	}

	void ShowInfo()
	{
		cout << "President: " << this->name << " Birthday: " << this->birthday << endl;
			
	}
	
	static President  GetInstance()
	{
		if (!instance)
		{
			instance = new GetInstance();
		}
		return instance;

	}

	
};


int main()
{
	President president1("Vladimir Zelensky", "25011978");
	cout << "							Variant 1" << endl;
	president1.ShowInfo();
	President presidenr2("Petro Poroshenko", "26091965");
	cout << "						Variant 2" << endl;
	presidenr2.ShowInfo();
	

	system("pause");
	return 0;
}