#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Case
{
	int priority;
	string tag;
	string nameAffair;
	string time;
public:

	Case() {};

	Case(int i)
	{
		cout << "Enter Priority Affair: "; cin >> this->priority;
		cout << "Enter Tag Affair: "; cin >> this->tag;
		cout << "Enter Mame Affair: "; cin >> this->nameAffair;
		cout << "Enter Date Affair: "; cin >> this->time;
	};

	virtual ~Case() {};

	int GetPriority() { return this->priority; };
	string GetTag() { return this->tag; };
	string GetNameAffair() { return this->nameAffair; };
	string GetTime() { return this->time; };

	void SetPriority(int priority) { this->priority = priority; };
	void SetTag(string tag) { this->tag = tag; }
	void SetNameAffair(string nameAffair) { this->nameAffair = nameAffair; }
	void SetTime(string time) { this->time = time; };


	//virtual void ShowInfo();
	//virtual void ShowAll() const = 0;
	//virtual void CreateToDoList() const = 0 ;//�������� ������ ���
	//virtual void SetExecutionDates() const = 0;//��������� ��� ����������
	//virtual void SetPriority_() const = 0;
	//virtual void DeleteAffair() const = 0; //��������
	//virtual void ChangeAffair() const = 0; //��������� ���
	//virtual void Read_from_file() const = 0; //��������� ����
	//virtual void Write_to_file() const = 0; // ��������� � ����
	//virtual void FindAffair() const = 0; //������ ����������� ����
	//virtual void FindAffair_by_Date() const = 0; //������ ����������� ���� �� ����
	//virtual void FindAffair_by_Tag() const = 0; //������ ����������� ���� �� ���� (�������� �� ��������)
	//virtual void FindAffair_by_Priority() const = 0; //������ ����������� ���� �� ����������
	//virtual bool Menu() const = 0;

	vector <Case> todolist;

	void ShowInfo()
	{
		cout << " " << this->priority << "\t     " << this->tag << "\t   " << this->nameAffair << "\t\t\t" << this->time << endl;
	};

	void ShowAll()
	{
		cout << "TO DO LIST " << endl;
		cout << "Priority    Tag    Name Affair                  Time" << endl;
		for (int i = 0; i < todolist.size(); i++)
		{
			cout << i + 1 << " ";
			todolist[i].ShowInfo();
		}

	}

	void Write_to_file()
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

	void Read_from_file()
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
				Case1 tmp;
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


	void FindAffair_by_Date()
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

	void FindAffair_by_Tag()
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

	void FindAffair_by_Priority()
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

	void ChangeAffair()
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


	void SetPriority_()
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


	void SetExecutionDates()
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



	void DeleteAffair()
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

	void FindAffair()
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


	bool Menu()
	{
		int choice;

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
			case 1:// "1.  Show to do list " << endl;
				system("cls");
				ShowAll();
				system("pause");
				break;

			case 2://"2.  Add new affair" << endl;
				system("cls");
				//				todolist.push_back(Case(1));
				system("pause");
				break;
			case 3://"3.  Set priorities Affair" << endl;
				system("cls");
				SetPriority_();
				system("pause");

				break;
			case 4://"4.  Set execution dates" << endl;
				system("cls");
				SetExecutionDates();
				system("pause");

				break;
			case 5://"5.  Delete Affair" << endl;
				system("cls");
				DeleteAffair();
				system("pause");

			case 6://"6.  Change Affair" << endl;
				system("cls");
				ChangeAffair();
				system("pause");

				break;
			case 7://"7.  Read from file list to do" << endl;
				system("cls");
				Read_from_file();
				system("pause");

				break;
			case 8://"8.  Save in file list to do" << endl;
				system("cls");
				Write_to_file();
				system("pause");

				break;
			case 9://"9.  Find affair" << endl;
				system("cls");
				FindAffair();
				system("pause");

				break;
			case 10://"10. Find affair by date" << endl;
				system("cls");
				FindAffair_by_Date();
				system("pause");

				break;
			case 11://"11. Find affair by tag" << endl;
				system("cls");
				FindAffair_by_Tag();
				system("pause");

				break;
			case 12://"12. Find affair by priority" << endl;
				system("cls");
				FindAffair_by_Priority();
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


class Case1 : public Case
{

public:
	


};


class System
{
public:
	virtual ~System() {};
	virtual Case *FactoryMethod()const = 0;

	void Operation() const
	{
		Case *case_ = this->FactoryMethod();
		delete case_;
	}
};

class System1: public System
{
public:
	Case *FactoryMethod()const override
	{
		return new Case1();
	}
};

void ClientCode(const System &system_)
{
	
	system_.Operation();
	
}

int main()
{
	System *planSystem = new System1();
	ClientCode(*planSystem);

	system("pause");
	return 0;
}