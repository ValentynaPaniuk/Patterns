#include<iostream>
#include<string>
using namespace std;

class Logger {
	string username;

	//статитчне поле контролю кількості об'єктів
	static Logger * logger_;

	//делегуючий конструктор
	Logger(string username) : username(username) {};

	//конструктор копіювання
	Logger(const Logger&) = delete;
	
	//приховані методи копіювання через оператор()
	Logger operator =(Logger&) = delete;
public:

	//Статичний метод, що повертає попереднє значення користувача
	static Logger *GetInstance(string username) {
		if (logger_ == nullptr) {
			logger_ = new Logger(username);
			cout << "Logined" << endl;
		}
		else {
			cout << "User already loggined." << endl;
		}
		return logger_;
	}

	//Метод виводу
	void ShowInfo() {
		cout << "Name: " << username << endl;
	}
};

Logger * Logger::logger_ = nullptr; //ініціалізація статичного поля

int main() {

	
	string username;
	cout << "Enter username: ";
	cin >> username;
	Logger::GetInstance(username)->ShowInfo();
	cout << "Enter username: ";
	cin >> username;
	Logger::GetInstance(username)->ShowInfo();

	system("pause");





	return 0;
}