#pragma once

#include <string>
#include <iostream>
#include <cmath>


class Operation
{
protected:
	std::string m_name;

public:
	Operation(std::string name) : m_name(name)
	{
	}

	std::string GetName() const
	{
		return m_name;
	}

	virtual void Execute() = 0;

};


class SummOperation : public Operation
{
public:
	SummOperation() : Operation("Summ")
	{
	}

	void Execute() override
	{
		double num1;
		double num2;
		std::cout << "Enter first number: ";
		std::cin >> num1;
		std::cout << "Enter second number: ";
		std::cin >> num2;
		std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
	}
};


class DeductOperation : public Operation
{
public:
	DeductOperation() : Operation("Deduct")
	{
	}

	void Execute() override
	{
		double num1;
		double num2;
		std::cout << "Enter minuend number: ";
		std::cin >> num1;
		std::cout << "Enter subtrahend: ";
		std::cin >> num2;
		std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
	}
};


class DivideOperation : public Operation
{
public:
	DivideOperation() : Operation("Divide")
	{
	}

	void Execute() override
	{
		double num1;
		double num2;
		std::cout << "Enter dividend number: ";
		std::cin >> num1;
		std::cout << "Enter divider: ";
		std::cin >> num2;
		if (num2 == 0)
		{
			std::cout << "Can not divided by 0" << std::endl;
			return;
		}
		std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
	}
};

class MultiplyOperation : public Operation
{
public:
	MultiplyOperation() : Operation("Multiply")
	{
	}

	void Execute() override
	{
		double num1;
		double num2;
		std::cout << "Enter first number: ";
		std::cin >> num1;
		std::cout << "Enter second number: ";
		std::cin >> num2;
		std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
	}
};


class SinusOperation : public Operation
{
public:
	SinusOperation() : Operation("Sinus")
	{
	}

	void Execute() override
	{
		double num;
		std::cout << "Enter number: ";
		std::cin >> num;
		std::cout << "Sin(" << num << ") = " << sin(num) << std::endl;
	}
};

class CosineOperation : public Operation
{
public:
	CosineOperation() : Operation("Cosine")
	{
	}

	void Execute() override
	{
		double num;
		std::cout << "Enter number: ";
		std::cin >> num;
		std::cout << "Cos(" << num << ") = " << cos(num) << std::endl;
	}
};


class ExponentOperation : public Operation
{
public:
	ExponentOperation() : Operation("Exponent")
	{
	}

	void Execute() override
	{
		double num;
		std::cout << "Enter degree: ";
		std::cin >> num;
		std::cout << "e^" << num << " = " << pow(2.718, num) << std::endl;
	}
};