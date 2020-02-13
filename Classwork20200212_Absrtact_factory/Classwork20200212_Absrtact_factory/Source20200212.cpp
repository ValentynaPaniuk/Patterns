#include <iostream>
#include <string>

using namespace std;

/*Завдання 1.  
Використати шаблон Абстрактна фабрика. 
Створити фабрики для створення кнопок та прапорців для ОС Windows, Macintosh  в залежності від вибору користувача.
Створити клас Клієнт(Application) для перевірки роботи фабрик.
Діаграма класів подібно 
*/


class AbstractProduct_button
{
public:
	virtual ~AbstractProduct_button() {};
	virtual void CreateButton()const = 0;
};


class Concrete_button1 : public AbstractProduct_button
{
public:
	void CreateButton() const override
	{
		cout << "Create button 1" << endl;
	}
};

class Concrete_button2 : public AbstractProduct_button
{
public:
	void CreateButton() const override
	{
		cout << "Create button 2" << endl;
	}
};



class AbstractProduct_flag
{
public:
	virtual ~AbstractProduct_flag() {};
	virtual void CreateFlag() const = 0;


	virtual void AnotherCreateFlag(const AbstractProduct_button &collaborator) const = 0;
};


class Concrete_flag1 : public AbstractProduct_flag
{

public:
	void CreateFlag()const override
	{
		cout << "Create flag 1" << endl;
	}

	void AnotherCreateFlag(const AbstractProduct_button &collaborator) const override
	{
		collaborator.CreateButton();
	}
};


class Concrete_flag2 : public AbstractProduct_flag
{

public:
	void CreateFlag()const override
	{
		cout << "Create flag 2" << endl;
	}

	void AnotherCreateFlag(const AbstractProduct_button &collaborator) const override
	{
		collaborator.CreateButton();
	}
};


class AbstractFactory
{
public:
	
	virtual AbstractProduct_button *CreateButton() const = 0;
	virtual AbstractProduct_flag *CreateFlag() const = 0;
};


class ConcretnaFabrica1 : public AbstractFactory
{
	AbstractProduct_button *CreateButton() const override
	{
		return new Concrete_button1();
	}
	AbstractProduct_flag *CreateFlag() const override
	{
		return new Concrete_flag1();
	}


};



class ConcretnaFabrica2 : public AbstractFactory
{
	AbstractProduct_button *CreateButton() const override
	{
		return new Concrete_button2();
	}
	AbstractProduct_flag *CreateFlag() const override
	{
		return new Concrete_flag2();
	}

};



void Client(const AbstractFactory &factory)
{
	AbstractProduct_button *button = factory.CreateButton();
	AbstractProduct_flag *flag = factory.CreateFlag();
	flag->CreateFlag();
	flag->AnotherCreateFlag(*button);

	delete button;
	delete flag;


}



int main()
{
	bool exit = false;
	int choice;
	int counter = 0;

	while (!exit)
	{
		cout << " Select a company: 1 - Windows, 2 - Macintosh " << " "; cin >> choice;
		if (choice == 1)
		{
			ConcretnaFabrica1 *windows = new ConcretnaFabrica1();
			Client(*windows);
			delete windows;
		}
		else if (choice == 2)
		{
			ConcretnaFabrica2 *macintosh = new ConcretnaFabrica2();
			Client(*macintosh);
			delete macintosh;
		}

		counter++;
		if (counter == 2)
		{
			exit = true;
		}
	}

	system("pause");
	return 0;
}