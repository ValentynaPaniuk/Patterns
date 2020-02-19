#include <iostream>
#include <string>

using namespace std;

/* Скласти програму Світлофор з використанням патерну Стан(State).*/

class Trafficlights;//Context

class Color //State
{
protected:
	Trafficlights *trafficlights;
public:
	virtual ~Color() {};

	void Set_Trafficlights(Trafficlights *trafficlights)
	{
		this->trafficlights = trafficlights;
	}

	virtual void Red() = 0;
	virtual void Green() = 0;

};


class Trafficlights
{
	Color *color_;
public:

	Trafficlights(Color *color) : color_(nullptr)
	{
		this->ChooseColor(color);
	}
	~Trafficlights() { delete color_; }

	void ChooseColor(Color *color)
	{
		cout << "1. Trafficlights: choose " << typeid(*color).name() <<"."<< endl;
		if (this->color_ != nullptr)
			delete this->color_;
		this->color_ = color;
		this->color_->Set_Trafficlights(this);
	}


	void RequestRed()
	{
		this->color_->Red();
	}
	void RequestGreen()
	{
		this->color_->Green();
	}

};

class ConcreteRed : public Color
{
public:
	void Red() override;

	void Green() override
	{
		cout << "2. Traffic light (RED) handles request Green() " << endl;
	}
};


class ConcreteGreen : public Color
{
public:
	void Red()override
	{
		cout << "3. Traffic light (GREEN) handles request Red()" << endl;
	}
	void Green() override
	{
		cout << "4. Traffic light (GREEN) handles request Green()" << endl;
		cout << "5. Traffic light (GREEN) wants to change the color of the Trafficlights" << endl;
		this->trafficlights->ChooseColor(new ConcreteRed);
	}
};



void ConcreteRed::Red()
{
	cout << "6. Traffic light (RED) handles request Red()" << endl;
	cout << "7. Traffic light (RED) wants to change the request of the Trafficlights" << endl;
	this->trafficlights->ChooseColor(new ConcreteGreen);
}




int main()
{
	Trafficlights *trafficlights = new Trafficlights(new ConcreteRed);
	
	trafficlights->RequestRed();
	trafficlights->RequestGreen();
	delete trafficlights;


	system("pause");
	return 0;

}
