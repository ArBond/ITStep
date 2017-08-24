#pragma once

#include "operation.h"
#include <vector>


class Calculator
{
private:
	std::vector<Operation*> m_operations = { 
		new SummOperation(), new DeductOperation(),
		new DivideOperation(), new MultiplyOperation(),
		new SinusOperation(), new CosineOperation(),
		new ExponentOperation() };

public:
	~Calculator()
	{
		auto it = m_operations.begin();
		while (it != m_operations.end())
		{
			delete *(it++);
		}
	}

	void ShowMenu()
	{
		int count = 1;
		for (auto it : m_operations)
		{
			std::cout << count++ << " - " << it->GetName() << "\n";
		}

		std::cout << "0 - Exit\nPlease choose operation: ";
	}

	std::vector<Operation*>::iterator Begin()
	{
		auto it = m_operations.begin();
		return it;
	}

	int GetOperationCuantity()
	{
		return m_operations.size();
	}

	void ExecuteOperation(Operation* operation)
	{
		operation->Execute();
	}
};