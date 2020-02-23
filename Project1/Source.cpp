#include <iostream>
#include <string>
#include <map>
#include<fstream>

using namespace std;

/*================================================================================
Implement the simplest task scheduling system using design patterns.
It should be possible to:
- creating a to-do list,
- setting priorities,
- setting of execution dates,
- removal,
- changes in cases.

Each case can be tagged.
The to-do list can be downloaded and saved to a file.
It is necessary to realize the possibility of finding a specific case.
Search criteria: by date, by tag, by priority, and so on.
===================================================================================
Реализуйте с использованием паттернов проектирования простейшую систему планирования задач. 
Должна быть возможность:
- создания списка дел, 
- установки приоритетов, 
- установки дат выполнения, 
- удаление,
- изменения дел. 

Каждому делу можно установить тег. 
Список дел можно загружать и сохранять в файл. 
Необходимо реализовать возможность поиска конкретного дела. 
Критерии поиска: по датам, по тегам, по приоритету и так далее.    */


class SchedulingSystem
{

	map<string, string> fields;

public:
	SchedulingSystem(string name = "Scheduling System") {}
	void Show() const
	{
		for (auto el : fields)
		{
			cout << el.first << "\t" << el.second << " ";
		}
		cout << endl;
	};


	string GetField(const string & key) const
	{
		return fields.at(key);
	};
	void SetField(const string & key, const string & value)
	{
		fields[key] = value;
	};

	
};

class SchedulingSystemBuilder abstract
{
protected:
	SchedulingSystem *list;
public:
	SchedulingSystemBuilder()
	{
		this->list = new SchedulingSystem();
	}
	SchedulingSystem *GetList()const
	{
		return this->list;
	}
	
	
	virtual void SetName() = 0;
	virtual void SetPriority() = 0;
	virtual void SetDate() = 0;

	virtual ~SchedulingSystemBuilder()
	{
		delete this->list;
	}
};

class List_New : public SchedulingSystemBuilder
{
public:
	List_New()
	{
		this->list = new SchedulingSystem("My plans");
	}

	void SetName()
	{
		string name;
		cout << "Add an event: " << endl; cin >> name;
		this->list->SetField("Name", name);
	}

	void SetPriority()
	{
		string priority;
		cout << "Specify importance(1 to 10) : " << endl; cin >> priority;
		this->list->SetField("priority", priority);
	}

	
	void SetDate()
	{
		string date;
		cout << "Enter the due dates: " << endl; cin >> date;
		this->list->SetField("date", date);
	}

};


class Director
{
public:
	
	void CreateSchedulingSystem(SchedulingSystemBuilder *build)
	{
		build->SetPriority();
		build->SetName();
		build->SetDate();
	}

	/*void Write_to_file()
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
			writeFile << "TOTAL NUMBER OF TASKS:" << todolist.size() << endl;
			writeFile << "Priority    Tag    Name Affair                      Time" << endl;
			for (int i = 0; i < todolist.size(); i++)
			{
				writeFile << todolist[i].GetPriority() << "\t\t";
				writeFile << todolist[i].GetTag() << "\t";
				writeFile << todolist[i].GetNameAffair() << "\t\t\t";
				writeFile << todolist[i].GetTime() << "\t\t";
				writeFile << endl;

			}
			cout << "File is saved" << endl;
		}
	}*/

};



int main()
{
	Director *planingList = new Director();
	SchedulingSystemBuilder *secretar = new List_New();
	planingList->CreateSchedulingSystem(secretar);
	secretar->GetList()->Show();
	delete secretar;
	delete planingList;

	system("pause");
	return 0;
}