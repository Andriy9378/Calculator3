#pragma once
#include <iostream>
using Number = double;

class calculator
{
private:
	Number save = 0;
	bool is_save_failled = false;
	Number number_ = 0;
public:
	void Set(Number n);
	Number GetNumber() const;
	void Add(Number n);
	void Sub(Number n);
	void Div(Number n);
	void Mul(Number n);
	void Pow(Number n);
	void Save();
	void Load();
	bool HasMem() const;
	std::string GetNumberRepr() const;
	void Clear();
};
