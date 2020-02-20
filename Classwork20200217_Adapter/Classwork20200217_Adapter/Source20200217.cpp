#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*Створити клас Студент(прізвище, ім’я, оцінка у 100 бальній шкалі). 
Створити клас-адаптер класу Студент, який надає інший спосіб виведення оцінки студента 
(у шкалі A-F).*/

class OldStudent
{
	
	
public:
	string name;
	string surname;
	int arr[5];
	int sum;

	OldStudent() 
	{
		cout << "Enter name: ";		cin >> this->name;
		cout << "Enter surname ";	cin >> this->surname;
		cout << " Enter five ratings (from 0 to 100): " << endl;
		this->sum = 0;
		for (int i = 0; i < 5; i++)
		{
			cin >> this->arr[i];
			this->sum += arr[i];
		}
	};
	~OldStudent() {};

	void Rating() 
	{
		cout << "Rating student " << this->name << " " << this->surname << " = " << this->sum / 5 << endl;
	};


};

class NewStudent : public OldStudent
{
public:
	NewStudent() {};
	~NewStudent() {};
	void Rating()
	{
		if ((this->sum) / 5 < 20)
			cout << "New rating student " << this->name << " " << this->surname <<" : " << this->sum/5  << " => " << "A" << endl;
		else if ((this->sum) / 5 > 20 && (this->sum) / 5 <= 40)
			cout << "New rating student " << this->name << " " << this->surname <<" : " << this->sum /5 << " => " << "B" << endl;
		else if ((this->sum) / 5 > 40 && (this->sum) / 5 <= 60)
			cout << "New rating student " << this->name << " " << this->surname <<" : " << this->sum /5 << " => " << "C" << endl;
		else if ((this->sum) / 5 > 60 && (this->sum) / 5 <= 80)
			cout << "New rating student " << this->name << " " << this->surname <<" : " << this->sum /5 << " => " << "D" << endl;
		else if ((this->sum) / 5 < 80)
			cout << "New rating student " << this->name << " " << this->surname <<" : " << this->sum /5 << " => " << "E" << endl;
	};

};








int main()
{

	OldStudent student;
	student.Rating();
	
	/*NewStudent newstudent;
	newstudent.Rating()*/;

	system("pause");
	return 0;
}