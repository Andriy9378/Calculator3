#include <iostream>
#include "calculator.h"

enum class Operators : char
{
	Add = '+', Minus = '-', Multiple = '*',
	Division = '/', Pow = '^', Equal = '=',
	Save = 's', Load = 'l', Set = ':',
	Clear = 'c', Negative = 'n', Quit = 'q'
};

bool RunCalculatorCycle();
bool ReadNumber(Number& result);

int main()
{
	RunCalculatorCycle();

	return 0;
}

bool RunCalculatorCycle()
{
	Operators op;

	bool use_safe = false;
	Number init_number;
	if (!ReadNumber(init_number))
		return false;
	calculator c;
	c.Set(init_number);
	std::string symbols;

	while (std::cin >> symbols)
	{
		Number right;

		char char_symbols = symbols.at(0);
		Operators op = static_cast<Operators>(char_symbols);

		switch (op)
		{
		case Operators::Add:
			if (!ReadNumber(right))
				return false;
			c.Add(right);
			break;
		case Operators::Minus:
			if (!ReadNumber(right))
				return false;
			c.Sub(right);
			break;
		case Operators::Multiple:
			if (!ReadNumber(right))
				return false;
			c.Mul(right);
			break;
		case Operators::Division:
			if (!ReadNumber(right))
				return false;
			c.Div(right);
			break;
		case Operators::Pow:
			if (!ReadNumber(right))
				return false;
			c.Pow(right);
			break;
		case Operators::Equal:
			std::cout << c.GetNumberRepr() << std::endl;
			break;
		case Operators::Save:
			if (!use_safe)
				use_safe = true;
			c.Save();
			break;
		case Operators::Load:
			if (use_safe)
			{
				c.Load();
				break;
			}
			else
			{
				std::cerr << "Error: Memory is emptry";
				return false;
			}
		case Operators::Set:
			if (!ReadNumber(right))
				return false;
			c.Set(right);
			break;
		case Operators::Clear:
			c.Clear();
			break;
		case Operators::Negative:
			if (!ReadNumber(right))
				return false;
			c.Set(-c.GetNumber());
			break;
		case Operators::Quit:
			return true;
		default:
			std::cerr << "Error: Unknown token" << " " << symbols;
			return false;
		}
	}

	return false;
}

bool ReadNumber(Number& result)
{
	if (!(std::cin >> result))
	{
		std::cout << "Error: Numeric operand expected" << std::endl;
		return false;
	}

	return true;
}
