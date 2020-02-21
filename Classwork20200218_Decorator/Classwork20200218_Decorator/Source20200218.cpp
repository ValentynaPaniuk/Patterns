#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Завдання 5. 
В програмі - грі, розробленій на минулих заняттях додати можливість створення різних типів юнітів. 
До кожного з юнітів додати можливість модифікації в різні типи юнітів: 
броньованого юніта, 
прискореного юніта, 
влучного юніта. 
Використати патерн Декоратор.*/

class Gamer abstract
{
public:
	virtual void Play() = 0;
	virtual ~Gamer() {}
};

class Archer : public Gamer
{
public:
	void Play() override
	{
		std::cout << "Archer plays" << std::endl;
	}
};

class ArmoredArcher : public Archer
{
public:
	void Play() override
	{
		std::cout << "Archer plays" << std::endl;
		ShowInfo();
	}

	void ShowInfo()
	{
		cout << "(He is armored)" << endl;
	}
};


class Mage : public Gamer
{
public:
	void Play() override
	{
		std::cout << "Mage plays" << std::endl;
	}
};

class AcceleratedMage : public Mage
{
public:
	void Play() override
	{
		std::cout << "Mage plays" << std::endl;
		ShowInfo();
	}

	void ShowInfo()
	{
		cout << "(He is accelerated)" << endl;
	}
};



class Swordsman : public Gamer
{
public:
	void Play() override
	{
		std::cout << "Swordsman plays" << std::endl;
	}
};

class AccurateSwordsman : public Swordsman
{
public:
	void Play() override
	{
		std::cout << "Swordsman plays" << std::endl;
		ShowInfo();
	}

	void ShowInfo()
	{
		cout << "(He is accurate)" << endl;
	}
};

enum Players {
	ARCHER = 1,
	ARMOREDARCHER,
	MAGE,
	ACCELERATEMAGE,
	SWORDSMAN,
	ACCURATESWORDMAN
};
class FabricMethod
{
public:
	static Gamer* createPlayer(Players typePlayer)
	{
		switch (typePlayer)
		{
		case ARCHER: return new Archer;
		case ARMOREDARCHER: return new ArmoredArcher;
		
		case MAGE: return new Mage;
		case ACCELERATEMAGE: return new AcceleratedMage;
		case ACCURATESWORDMAN: return new AccurateSwordsman;
		default:
		case SWORDSMAN:
			return new Swordsman;
		}
	}
};



int main()
{
	vector <Gamer*> team;

	int choice;
	while (true)
	{
		cout << "1 - Archer\n2 - Armored archer\n3 - Mage\n4 - Accelerated mage\n5 - Swordsman\n6 - Accurate swordsman\n0 - exit\n";
		cin >> choice;

		if (choice == 0)
			break;
		team.push_back(FabricMethod::createPlayer((Players)choice));
		//	team.push_back(factory[choice - 1]->createPlayer());
	}

	for (auto el : team)
	{
		el->Play();

	
	}
	for (auto el : team)
	{
		delete el;
	}


	system("pause");
	return 0;
}