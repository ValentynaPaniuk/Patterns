#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;
/*
Реализуйте с использованием паттернов проектирования простейшую систему планирования задач. 
Должна быть возможность создания списка дел, установки приоритетов, установки дат выполнения, 
удаление и изменения дел. 
Каждому делу можно установить тег. 
Список дел можно загружать и сохранять в файл. 
Необходимо реализовать возможность поиска конкретного дела. 
Критерии поиска: по датам, по тегам, по приоритету и так далее.

=====================================================================

Implement the simplest task scheduling system using design patterns.
It should be possible to create a to-do list, set priorities, set execution dates,
removal and change of affairs.
Each case can be tagged.
To-do list can be downloaded and saved to a file.
It is necessary to realize the possibility of finding a specific case.
Search criteria: by date, by tag, by priority, and so on.

*/


class PlanningSystem
{
public:
	virtual void CreateToDoList() {} ;//создания списка дел
	virtual void SetPriorities() {}; //установки приоритетов
	virtual void SetExecutionDates() {};//установки дат выполнения
	virtual void DeleteAffair() {}; //удаление
	virtual void ChangeAffair() {}; //изменения дел
	virtual void ReadFromFile() {}; //загружать файл
	virtual void SaveFile() {}; // сохранять в файл
	virtual void FindAffair() {}; //поиска конкретного дела
	virtual void FindAffair_by_Date() {}; //поиска конкретного дела по дате
	virtual void FindAffair_by_Tag() {}; //поиска конкретного дела по тегу (виконано не виконано)
	virtual void FindAffair_by_Priority() {}; //поиска конкретного дела по приоритету

	
};

class Affair
{
	int priority;
	string tag;
	string nameAffair;
	string time;


public:
	Affair() {};
	~Affair() {};

	Affair(int priority, string tag, string nameAffair, string time)
	{

		this->priority = priority;
		this->tag = tag;
		this->nameAffair = nameAffair;
		this->time = time;
	}

	int GetPriority()	   { return this->priority; };
	string GetTag()		   { return this->tag; };
	string GetNameAffair() { return this->nameAffair; };
	string GetTime()       { return this->time; };

	void SetPriority(int priority)		  { this->priority = priority; };
	void SetTag(string tag)				  { this->tag = tag; }
	void SetNameAffair(string nameAffair) { this->nameAffair = nameAffair; }
	void SetTime(string time)			  { this->time = time; };

	void ShowInfo()
	{
		cout <<" "<< this->priority << "\t     " << this->tag << "\t   " << this->nameAffair << "\t\t\t" << this->time << endl;
	}
	


};


void ShowAll(vector <Affair> &todolist)
{
	cout << "TO DO LIST " << endl;
	cout << "Priority    Tag    Name Affair                  Time" << endl;
	for (vector<Affair>::const_iterator i = todolist.begin(); i < todolist.end(); i++)
	{
		Affair(*i).ShowInfo();
	}

}

void Write_to_file(vector <Affair> todolist)
{
	ofstream writeFile;
	string path = "data.txt";
	writeFile.open(path);
	if (!writeFile.is_open())
	{
		cout << "Can't write file" << endl;
	}
	else
	{
		writeFile <<"TOTAL NUMBER OF TASKS:"<< todolist.size()  << endl;
		writeFile<< "Priority    Tag    Name Affair                      Time" << endl;
		for (int i = 0; i < todolist.size() ; i++)
		{
			writeFile << todolist[i].GetPriority()<<"\t\t";
			writeFile << todolist[i].GetTag() << "\t";
			writeFile << todolist[i].GetNameAffair() << "\t\t\t";
			writeFile << todolist[i].GetTime() << "\t\t";
			writeFile << endl;
			
		}
		cout << "File is saved" << endl;
	}
}

void Read_from_file(vector <Affair> &todolist)
{
	string path = "data1.txt";
	ifstream readFile;
	readFile.open(path);
	if (!readFile.is_open())
	{
		cout << "Can't open file " << endl;
	}
	else
	{
		cout << "File is open" << endl;
		while (!readFile.eof())
		{
			char temp[255];
			Affair tmp;
			readFile.getline(temp, 255);
			tmp.SetPriority(atoi(temp));
			readFile.getline(temp, 255);
			tmp.SetTag(temp);
			readFile.getline(temp, 255);
			tmp.SetNameAffair(temp);
			readFile.getline(temp, 255);
			tmp.SetTime(temp);
			todolist.push_back(tmp);
		}
	}
	readFile.close();
	
}


void FindAffair_by_Date(vector <Affair> &todolist)
{
	string tmp;
	bool exit = false;
	cout << "What is the date of the search job ? " << endl; cin >> tmp;

	for (int i = 0; i < todolist.size(); i++)
	{
		

		if (tmp == todolist[i].GetTime())
		{
			todolist[i].ShowInfo();
			exit = true;
		}
	}
	if(!exit)
	{
		cout << "Please enter the date correctly" << endl;
	}
	
}

void FindAffair_by_Tag(vector <Affair> &todolist)
{
	string tmp;
	bool exit = false;
	cout << "What is the tag of the search job ? " << endl; cin >> tmp;

	for (int i = 0; i < todolist.size(); i++)
	{


		if (tmp == todolist[i].GetTag())
		{
			todolist[i].ShowInfo();
			exit = true;
		}
	}
	if (!exit)
	{
		cout << "Please enter the tag correctly" << endl;
	}

}

void FindAffair_by_Priority(vector <Affair> &todolist)
{
	int tmp;
	bool exit = false;
	cout << "What is the priority of the search job ? " << endl; cin >> tmp;

	for (int i = 0; i < todolist.size(); i++)
	{


		if (tmp == todolist[i].GetPriority())
		{
			todolist[i].ShowInfo();
			exit = true;
		}
	}
	if (!exit)
	{
		cout << "Please enter the priority correctly" << endl;
	}

}

void ChangeAffair(vector <Affair> &todolist)
{

};


bool Menu()
{ 
	int choice;
	vector <Affair> list;

	for (;;) {
		cout << "========= Planning System =============" << endl;
		cout << "1.  Show to do list " << endl;
		cout << "2.  Add new affair" << endl;
		cout << "3.  Set priorities Affair" << endl;
		cout << "4.  Set execution dates" << endl;
		cout << "5.  Delete Affair" << endl;
		cout << "6.  Change Affair" << endl;
		cout << "7.  Read from file list to do" << endl;
		cout << "8.  Save in file list to do" << endl;
		cout << "9.  Find affair" << endl;
		cout << "10. Find affair by date" << endl;
		cout << "11. Find affair by tag" << endl;
		cout << "12. Find affair by priority" << endl;
		cout << "0.  Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");

		case 2:
			system("cls");

			break;
		case 3:
			system("cls");

			break;
		case 4:
			system("cls");

			break;
		case 5:
			system("cls");

		case 6:
			system("cls");

			break;
		case 7:
			system("cls");

			break;
		case 8:
			system("cls");

			break;
		case 9:
			system("cls");

			break;
		case 10:
			system("cls");

			break;
		case 11:
			system("cls");

			break;
		case 12:
			system("cls");

			break;
		case 0:
			system("cls");
			return false;
			break;
		default:
			break;
		}
	}
	
}


int main()
{
	vector <Affair> list;
	list.push_back(Affair(10, "+", "Write list", "20200218"));
	list.push_back(Affair(5, "-", "Write new list", "20200205"));
	cout << "Write" << endl;
	Write_to_file(list);
	ShowAll(list);
	cout << "Read" << endl;
	Read_from_file(list);
	ShowAll(list);
	cout << "Find date" << endl;
	FindAffair_by_Date(list);
	FindAffair_by_Tag(list);
	FindAffair_by_Priority(list);
	
	
	
	system("pause");
	return 0;
}