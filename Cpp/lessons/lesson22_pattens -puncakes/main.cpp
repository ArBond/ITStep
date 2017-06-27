#include "Order.h"
#include <iostream>

enum SupplimentType
{
	Bacon,
	Onion,
	Chocolate,
	Jam
};

IOrder* AddSuppliment(IOrder* order, SupplimentType type, size_t count)
{
	switch (type)
	{
	case Bacon:
		return new BaconSup(order, count);
	case Onion:
		return new OnionSup(order, count);
	case Chocolate:
		return new ChocolateSup(order, count);
	case Jam:
		return new JamSup(order, count);
	default:
		return order;
	}
}

void PrintCheck(IOrder* order)
{
	std::cout << "Your order:\n" <<
		order->GetName() << "\n\n" <<
		"Cost: " << order->GetCost() << "\n";
}

IOrder* ApplyDiscount(IOrder* order)
{
	return new Discount(order);
}

void main()
{
	IOrder* order = new CheeseAndTomatoPancake();
	order = AddSuppliment(order, Bacon, 3);
	order = AddSuppliment(order, Onion, 2);

	order = ApplyDiscount(order);

	PrintCheck(order);
	delete order;

}
