#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

/*Each case can be tagged.
The to - do list can be downloaded and saved to a file.
It is necessary to realize the possibility of finding a specific case.
Search criteria : by date, by tag, by priority, and so on.
================================================================================== =
Реализуйте с использованием паттернов проектирования простейшую систему планирования задач.
Должна быть возможность :
-создания списка дел,
-установки приоритетов,
-установки дат выполнения,
-удаление,
-изменения дел.

Каждому делу можно установить тег.
Список дел можно загружать и сохранять в файл.
Необходимо реализовать возможность поиска конкретного дела.
Критерии поиска : по датам, по тегам, по приоритету и так далее.*/

	////////////////////virtual void CreateToDoList() {} ;//создания списка дел
	////////////////////virtual void SetPriorities() {}; //установки приоритетов
	////////////////////virtual void SetExecutionDates() {};//установки дат выполнения
	////////////////////virtual void DeleteAffair() {}; //удаление
	////////////////////virtual void ChangeAffair() {}; //изменения дел
	////////////////////virtual void ReadFromFile() {}; //загружать файл
	////////////////////virtual void SaveFile() {}; // сохранять в файл
	////////////////////virtual void FindAffair() {}; //поиска конкретного дела
	////////////////////virtual void FindAffair_by_Date() {}; //поиска конкретного дела по дате
	////////////////////virtual void FindAffair_by_Tag() {}; //поиска конкретного дела по тегу (виконано не виконано)
	////////////////////virtual void FindAffair_by_Priority() {}; //поиска конкретного дела по приоритету







class Affair
{
	int priority;
	string tag;
	string nameAffair;
	string time;


public:
	Affair() {};

	Affair(int i) 
	{
		cout << "Enter Priority Affair: "; cin >> this->priority;
		cout << "Enter Tag Affair: "; cin >> this->tag;
		cout << "Enter Mame Affair: "; cin >> this->nameAffair;
		cout << "Enter Date Affair: "; cin >> this->time;
	};

	
	~Affair() {};

	
	Affair(int priority, string tag, string nameAffair, string time)
	{

		this->priority = priority;
		this->tag = tag;
		this->nameAffair = nameAffair;
		this->time = time;
	}

public:
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




class PlanningSystem : protected Affair
{
	void ShowAll(vector <Affair> &todolist)
	{
		cout << "TO DO LIST " << endl;
		cout << "Priority    Tag    Name Affair                  Time" << endl;
		for (int i = 0; i < todolist.size(); i++)
		{
			cout << i + 1 << " ";
			todolist[i].ShowInfo();
		}

	}
	
	void Write_to_file(vector <Affair> &todolist)
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
		if (!exit)
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
		int x;
		bool exit = false;
		cout << "Enter the case number that you want to change: " << endl; cin >> x;

		for (int i = 0; i < todolist.size(); i++)
		{


			if ((x - 1) == i)
			{
				string text;
				cout << "Enter the corrected case: " << endl; cin >> text;
				todolist[i].SetNameAffair(text);
				todolist[i].ShowInfo();
				exit = true;
			}
		}
		if (!exit)
		{
			cout << "Please enter the number correctly" << endl;
		}


	};


	void SetPriority_(vector <Affair> &todolist)
	{
		int x;
		bool exit = false;
		cout << "Enter the case number that you want to change: " << endl; cin >> x;

		for (int i = 0; i < todolist.size(); i++)
		{


			if ((x - 1) == i)
			{
				int text;
				cout << "Enter the corrected priority (from 1 to 10): " << endl; cin >> text;
				todolist[i].SetPriority(text);
				todolist[i].ShowInfo();
				exit = true;
			}
		}
		if (!exit)
		{
			cout << "Please enter the number correctly" << endl;
		}


	};

	
	void SetExecutionDates(vector <Affair> &todolist)
	{
		int x;
		bool exit = false;
		cout << "Enter the case number that you want to change: " << endl; cin >> x;

		for (int i = 0; i < todolist.size(); i++)
		{
			if ((x - 1) == i)
			{
				string text;
				cout << "Enter the corrected execution day: " << endl; cin >> text;
				todolist[i].SetTime(text);
				todolist[i].ShowInfo();
				exit = true;
			}
		}
		if (!exit)
		{
			cout << "Please enter the number correctly" << endl;
		}


	};



	void DeleteAffair(vector <Affair> &todolist)
	{
		int x;
		bool exit = false;
		cout << "Enter the case number that you want to delete: " << endl; cin >> x;

		for (int i = 0; i < todolist.size(); i++)
		{
			if ((x - 1) == i)
			{
				todolist.erase(todolist.begin() + i);
				cout << "Succesfull" << endl;

				exit = true;
			}
		}
		if (!exit)
		{
			cout << "Please enter the priority correctly" << endl;
		}


	};

	void FindAffair(vector <Affair> &todolist)
	{
		int x;
		bool exit = false;
		cout << "Enter the case number that you want to find: " << endl; cin >> x;

		for (int i = 0; i < todolist.size(); i++)
		{
			if ((x - 1) == i)
			{
				todolist[i].ShowInfo();
				exit = true;
			}
		}
		if (!exit)
		{
			cout << "Please enter the number correctly" << endl;
		}
	}
protected:

	vector <Affair> todolist;


public:
	
	bool Menu(vector <Affair> todolist)
	{
		int choice = 7;

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
			Read_from_file(todolist);
			
			//cin >> choice;
			switch (choice)
			{
			case 1:// "1.  Show to do list " << endl;
				system("cls");
				ShowAll(todolist);
				system("pause");
				break;

			case 2://"2.  Add new affair" << endl;
				system("cls");
				todolist.push_back(Affair(1));
				system("pause");
				break;
			case 3://"3.  Set priorities Affair" << endl;
				system("cls");
				SetPriority_(todolist);
				system("pause");

				break;
			case 4://"4.  Set execution dates" << endl;
				system("cls");
				SetExecutionDates(todolist);
				system("pause");

				break;
			case 5://"5.  Delete Affair" << endl;
				system("cls");
				DeleteAffair(todolist);
				system("pause");

			case 6://"6.  Change Affair" << endl;
				system("cls");
				ChangeAffair(todolist);
				system("pause");

				break;
			case 7://"7.  Read from file list to do" << endl;
				system("cls");
				Read_from_file(todolist);
				ShowAll(todolist);

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
				system("pause");

				break;
			case 8://"8.  Save in file list to do" << endl;
				system("cls");
				Write_to_file(todolist);
				system("pause");

				break;
			case 9://"9.  Find affair" << endl;
				system("cls");
				FindAffair(todolist);
				system("pause");

				break;
			case 10://"10. Find affair by date" << endl;
				system("cls");
				FindAffair_by_Date(todolist);
				system("pause");

				break;
			case 11://"11. Find affair by tag" << endl;
				system("cls");
				FindAffair_by_Tag(todolist);
				system("pause");

				break;
			case 12://"12. Find affair by priority" << endl;
				system("cls");
				FindAffair_by_Priority(todolist);
				system("pause");

				break;
			case 0://"0.  Exit" << endl;
				system("pause");
				return false;
				break;
			default:
				break;
			}
		}

	}
	


};







int main()
{
	vector <Affair> todolist;
	PlanningSystem list;
	list.Menu(todolist);
	
		
	

	
	
	system("pause");
	return 0;
}