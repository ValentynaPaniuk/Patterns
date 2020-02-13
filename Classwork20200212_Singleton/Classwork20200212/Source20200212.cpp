#include <iostream>
#include <string>

using namespace std;

/*1. Написати клас Logger в якому можна залогінитись лише один раз. (Singleton) 
у випадку якщо екземпляр класу вже створений, повертати відповідне повідомлення*/


class Logger {
	string name;

	//статитчне поле контролю кількості об'єктів
	static Logger * logger;

	//делегуючий конструктор
	Logger(string username) : name(name) {};

	//конструктор копіювання
	Logger(const Logger&) = delete;

	//приховані методи копіювання через оператор()
	Logger operator =(Logger&) = delete;
public:

	//Статичний метод, що повертає попереднє значення користувача
	static Logger *GetInstance(string name) {
		if (logger == nullptr) {
			logger = new Logger(name);
			cout << "Logined" << endl;
		}
		else {
			cout << "User already loggined." << endl;
		}
		return logger;
	}

	//Метод виводу
	void ShowInfo() {
		cout << "Name: " << name << endl;
	}
};

Logger * Logger::logger = nullptr; //ініціалізація статичного поля

int main()
{
	string name;
	cout << "Enter username: ";
	cin >> name;
	Logger::GetInstance(name)->ShowInfo();
	cout << "Enter username: ";
	cin >> name;
	Logger::GetInstance(name)->ShowInfo();


	system("pause");
	return 0;
}