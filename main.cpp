#include <iostream>
#include "calculator.h"

bool RunCalculatorCycle();
bool ReadNumber(Number& result);

int main()
{
	RunCalculatorCycle();

	return 0;
}

bool RunCalculatorCycle()
{
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

		if (symbols == "+")
		{
			if (!ReadNumber(right))
				return false;
			c.Add(right);
		}

		else if (symbols == "-")
		{
			if (!ReadNumber(right))
				return false;
			c.Sub(right);
		}

		else if (symbols == "*")
		{
			if (!ReadNumber(right))
				return false;
			c.Mul(right);
		}

		else if (symbols == "/")
		{
			if (!ReadNumber(right))
				return false;
			c.Div(right);
		}

		else if (symbols == "**")
		{
			if (!ReadNumber(right))
				return false;
			c.Pow(right);
		}

		else if (symbols == "=")
		{
			std::cout << c.GetNumberRepr() << std::endl;
		}

		else if (symbols == "s")
		{
			if (!use_safe)
				use_safe = true;

			c.Save();
		}

		else if (symbols == "l")
		{
			if (use_safe)
				c.Load();

			else
			{
				std::cerr << "Error: Memory is emptry";
				return false;
			}
		}

		else if (symbols == ":")
		{
			if (!ReadNumber(right))
				return false;
			c.Set(right);
		}

		else if (symbols == "c")
		{
			c.Clear();
		}

		else if (symbols == "n")
		{
			if (!ReadNumber(right))
				return false;
			c.Set(-c.GetNumber());
		}

		else if (symbols == "q")
		{
			return true;
		}

		else
		{
			std::cerr << "Error: Unknown token" << " " << symbols;
			return false;
		}
	}
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
