#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

/*клас «Конвеєр»
Метод «Зібрати» цього класу буде виконувати процес конструювання за допомогою виконання цих кроків
без залежності від технічних деталей реалізації кожного кроку.
З загальної технологічної точки зору, автомобіль на конвеєрі проходить такі етапи:
1.	Збірка кузова.
2.	Установка двигуна.
3.	Установка коліс.
4.	Фарбування.
5.	Підготовка салону.
Завод може виробляти автомобілі наступних моделей: автомобілі класу «міні», спортивні автомобілі, позашляховики.

Відповідальність за реалізацію кроків конструювання покласти на абстрактний клас, по типу «ТехнологіяМоделі». 
В результаті застосування конкретних підкласів класу «ТехнологіяМоделі» ми отримуємо на виході різні моделі автомобілів, 
тобто екземпляри різних класів автомобілів. У нашому випадку визначити такі підкласи класу «ТехнологіяМоделі»: 
«ТехнологіяМініАвто», 
«ТехнологіяСпортивнеАвто», 
«ТехнологіяПозашляховеАвто». 
Кожна з цих технологій відповідно передбачає випуск таких моделей автомобілів: «МініАвто», «СпортивнеАвто», «ПозашляховеАвто».
Для початку виробництва автомобіля необхідно задати конкретну технологію для конвеєра і викликати метод «Зібрати». 
Після завершення процесу складання готовий автомобіль можна отримати у об'єкта технології за допомогою методу «ОтриматиРезультат()».

*/


class Car
{
	string name;
	map <string, string > parts;
public:

	Car(string name = "car") : name(name) {};

	void ShowCar() const
	{
		cout << "================\nCAR: " << name << endl;
		for (auto el : parts)
		{
			cout << el.first << "\t\t\t" << el.second << endl;
		}
	}

	string GetParts(const string & key) const 
	{
		return parts.at(key);
	}
	void SetPart(const string & key, const string & value) 
	{
		parts[key] = value;
	}

};



class CarConveyor abstract
{
protected:
	Car *car;
public:

	CarConveyor()
	{
		this->car = new Car();
	}
	Car *GetCar()const
	{
		return this->car;
	}

	virtual void SetBodyAssembly() = 0;
	virtual void SetEngine() = 0;
	virtual void SetWheels() = 0;
	virtual void SetPainting() = 0;
	virtual void SetSalon() = 0;

	virtual ~CarConveyor()
	{
		delete this->car;
	}
};


class MiniAuto : public CarConveyor
{
public:
	MiniAuto()
	{
		this->car = new Car("MiniAuto");
	}

	void SetBodyAssembly()
	{
		this->car->SetPart("Body Assembly", "Yes");
	};
	void SetEngine()
	{
		this->car->SetPart("Engine      ", "Yes");
	};
	void SetWheels()
	{
		this->car->SetPart("Wheels       ", "Yes");
	};
	void SetPainting()
	{
		this->car->SetPart("Painting     ", "Red");
	};
	void SetSalon()
	{
		this->car->SetPart("Salon        ", "Yes");
	};

	
};
	
class SportAuto : public CarConveyor
{
public:
	SportAuto()
	{
		this->car = new Car("SportAuto");
	}

	void SetBodyAssembly()
	{
		this->car->SetPart("Body Assembly", "Yes 1");
	};
	void SetEngine()
	{
		this->car->SetPart("Engine       ", "Yes 1");
	};
	void SetWheels()
	{
		this->car->SetPart("Wheels      ", "Yes 1");
	};
	void SetPainting()
	{
		this->car->SetPart("Painting    ", "Blue");
	};
	void SetSalon()
	{
		this->car->SetPart("Salon       ", "Yes 1");
	};

};

class RoadAuto : public CarConveyor
{
public:
	RoadAuto()
	{
		this->car = new Car("RoadAuto");
	}

	void SetBodyAssembly()
	{
		this->car->SetPart("Body Assembly", "Yes 2");
	};
	void SetEngine()
	{
		this->car->SetPart("Engine      ", "Yes 2");
	};
	void SetWheels()
	{
		this->car->SetPart("Wheels      ", "Yes 2");
	};
	void SetPainting()
	{
		this->car->SetPart("Painting     ", "Yelow");
	};
	void SetSalon()
	{
		this->car->SetPart("Salon        ", "Yes 2");
	};

};


class ModelTechnology
{
public:
	void CreateCar(CarConveyor *conveyor)
	{
		conveyor->SetBodyAssembly();
		conveyor->SetEngine();
		conveyor->SetWheels();
		conveyor->SetPainting();
		conveyor->SetSalon();

					
			
	}
};

int main()
{
	ModelTechnology *transport = new ModelTechnology();
	CarConveyor *one = new MiniAuto();
	transport->CreateCar(one);
	one->GetCar()->ShowCar();

	cout << " ========================= " << endl;
	CarConveyor *two = new SportAuto();
	transport->CreateCar(two);
	two->GetCar()->ShowCar();

	cout << " ========================= " << endl;
	CarConveyor *tree = new RoadAuto();
	transport->CreateCar(tree);
	tree->GetCar()->ShowCar();



	system("pause");
	return 0;
}