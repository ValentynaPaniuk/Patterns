#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;

/*Завдання 1. Скласти програму, що забезпечує створення щоденного та тижневого звіту
продажів для деякого магазину у форматі текстового файлу та html-файлу. 
Використати патерн Міст.*/

class Report
{
public:

	virtual string GetQuantity()const = 0;
};

class DailyReport : public Report
{
public:
	string GetQuantity() const
	{
		return "10 kg of apples";
	}
};

class WeeklyReport : public Report
{
public:
	string GetQuantity() const
	{
		return "70 kg of apples";
	}
};

class Shop
{
protected:
	string salesVolumes;

public:
	Shop(string str) :salesVolumes(str) {}
	virtual string GetSalesVolumes() = 0;
	virtual void WriteFile_html(vector <Shop*> report) = 0;
	virtual void WriteFile_txt(vector <Shop*> report) = 0;
};



class DailyShop : public Shop
{
	Report *report;
public: DailyShop(Report *report, string str = "Supermarket Vopak") : Shop(str), report(report) {}
		string GetSalesVolumes()
		{
			return "Daily report: " + report->GetQuantity();
		}

		void WriteFile_txt(vector <Shop*> report)
		{
			cout << "Daily report txt: " << endl;
			ofstream writeFile;
			string path = "data.txt";
			writeFile.open(path);
			if (!writeFile.is_open())
			{
				cout << "Can't write file! " << endl;
			}
			else
			{
				writeFile << report.size() - 1 << endl;
				for (int i = 0; i < report.size() - 1; i++)
				{
					writeFile << "Report: " << i + 1 << endl;
					writeFile << report[i]->GetSalesVolumes() << endl;
				}
				cout << "File is saved" << endl;
			}
		}

		void WriteFile_html(vector <Shop*> report)
		{
			cout << "Daily report html: " << endl;
			ofstream writeFile;
			string path = "data.html";
			writeFile.open(path);
			if (!writeFile.is_open())
			{
				cout << "Can't write file! " << endl;
			}
			else
			{
				writeFile << report.size() - 1 << endl;
				for (int i = 0; i < report.size() - 1; i++)
				{
					writeFile << "<ul> " << endl;
					writeFile << "		<li> " << endl;
					writeFile << "			" << report[i]->GetSalesVolumes() << endl;
					writeFile << "		<li> " << endl;
					writeFile << "<ul> " << endl;
				}
				cout << "File is saved" << endl;
			}
		}



	

};

class WeeklyShop : public Shop
{
	Report *report;
public: WeeklyShop(Report *report, string str = "Supermarket Vopak") : Shop(str), report(report) {}
		string GetSalesVolumes()
		{
			return "Weekly report: " + report->GetQuantity();
		}


		void WriteFile_txt(vector <Shop*> report)
		{
			cout << "Weekly report txt : " << endl;
			ofstream writeFile;
			string path = "data.txt";
			writeFile.open(path);
			if (!writeFile.is_open())
			{
				cout << "Can't write file! " << endl;
			}
			else
			{
				writeFile << report.size() - 1 << endl;
				for (int i = 0; i < report.size() - 1; i++)
				{
					writeFile << "Report: " << i + 1 << endl;
					writeFile << report[i]->GetSalesVolumes() << endl;
				}
				cout << "File is saved" << endl;
			}
		}

		void WriteFile_html(vector <Shop*> report)
		{
			cout << " Weekly report html: " << endl;
			ofstream writeFile;
			string path = "data.html";
			writeFile.open(path);
			if (!writeFile.is_open())
			{
				cout << "Can't write file! " << endl;
			}
			else
			{
				writeFile << report.size() - 1 << endl;
				for (int i = 0; i < report.size() - 1; i++)
				{
					writeFile << "<ul> " << endl;
					writeFile << "		<li> " << endl;
					writeFile << "			" << report[i]->GetSalesVolumes() << endl;
					writeFile << "		<li> " << endl;
					writeFile << "<ul> " << endl;
				}
				cout << "File is saved" << endl;
			}
		}


};




int main()
{
	Report *one = new DailyReport();
	Report *two = new WeeklyReport();

	vector<Shop*> report;

	report.push_back(new DailyShop(one));
	report.push_back(new WeeklyShop(two));

	for (int i = 0; i < report.size(); i++)
	{
		cout<< report[i]->GetSalesVolumes()<<endl;
	}



	for (int i = 0; i < report.size(); i++)
	{
		report[i]->WriteFile_txt(report);
	}
	
	for (int i = 0; i < report.size(); i++)
	{
		report[i]->WriteFile_html(report);
	}
	
	
	
	
	
	system("pause");
	return 0;
}