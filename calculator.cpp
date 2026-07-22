#include "calculator.h"
#include <string>
#include <cmath>
using Number = double;

void calculator::Set(Number n)
{
	number_ = n;
}

Number calculator::GetNumber() const
{
	return number_;
}

void calculator::Add(Number n)
{
	number_ += n;
}

void calculator::Sub(Number n)
{
	number_ -= n;
}

void calculator::Div(Number n)
{
	number_ /= n;
}

void calculator::Mul(Number n)
{
	number_ *= n;
}

void calculator::Pow(Number n)
{
	number_ = std::pow(number_, n);
}

void calculator::Save()
{
	save = number_;
	is_save_failled = true;
}

void calculator::Load()
{
	number_ = save;
}

bool calculator::HasMem() const
{
	if (is_save_failled)
		return true;

	else
		return false;
}

std::string calculator::GetNumberRepr() const
{
	return std::to_string(number_);
}

void calculator::Clear()
{
	number_ = 0;
}
