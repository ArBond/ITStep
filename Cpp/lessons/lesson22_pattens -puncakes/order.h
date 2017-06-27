#pragma once
#include <string>


class IOrder
{
public:
	virtual ~IOrder() = default;

	virtual std::string GetName() = 0;
	virtual double GetCost() = 0;

private:

};

class Pancake : public IOrder
{
public:
	std::string GetName()
	{
		return "Pancake with butter";
	}

	double GetCost()
	{
		return 0.5;
	}
};

class CheeseAndTomatoPancake : public IOrder
{
public:
	std::string GetName()
	{
		return "Pancake with cheese and tomato";
	}

	double GetCost()
	{
		return 1.5;
	}
};

class BananaPancake : public IOrder
{
public:
	std::string GetName()
	{
		return "Pancake with banana";
	}

	double GetCost()
	{
		return 1.0;
	}
};

class StrawberryPancake : public IOrder
{
public:
	std::string GetName()
	{
		return "Pancake with strawberry";
	}

	double GetCost()
	{
		return 1.2;
	}
};

class Suppliments : public IOrder
{
private:
	IOrder* m_decorate;
	double m_cost;
	std::string m_name;
	size_t m_count = 0;
public:
	Suppliments(IOrder* decorate, double cost, std::string name, size_t count) :
		m_decorate(decorate),
		m_cost(cost),
		m_name(name),
		m_count(count)
	{
	}

	~Suppliments()
	{
		delete m_decorate;
	}

	double GetCost()
	{
		return m_decorate->GetCost() + m_cost * m_count;
	}

	std::string GetName()
	{
		std::string str = m_decorate->GetName() + ", " + m_name;
		if (m_count > 1)
		{
			str += "*" + std::to_string(m_count);
		}
		return str;
	}
};

class BaconSup : public Suppliments
{
public:
	BaconSup(IOrder* decorate, size_t count) : Suppliments(decorate, 0.5, "bacon", count)
	{
	}
};

class OnionSup : public Suppliments
{
public:
	OnionSup(IOrder* decorate, size_t count) : Suppliments(decorate, 0.2, "onion", count)
	{
	}

};

class ChocolateSup : public Suppliments
{
public:
	ChocolateSup(IOrder* decorate, size_t count) : Suppliments(decorate, 0.8, "chocolate", count)
	{
	}

};

class JamSup : public Suppliments
{
public:
	JamSup(IOrder* decorate, size_t count) : Suppliments(decorate, 0.5, "jam", count)
	{
	}
};

class Discount : public IOrder
{
private:
	IOrder* m_decorate;
public:
	Discount(IOrder* order) :m_decorate(order)
	{
	}

	double GetCost()
	{
		double cost = m_decorate->GetCost();
		return cost >= 3 ? cost * 0.9 : cost;
	}

	std::string GetName()
	{
		std::string str = m_decorate->GetName();
		if (m_decorate->GetCost() >= 3)
		{
			str += "(Discount: 10%)";
		}
		return str;
	}
};