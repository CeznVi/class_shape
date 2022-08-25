#pragma once
#include <string>

//абстрактний клас
class Shape
{
protected:
	string name = "no_name";
	int x{}, y{};
public:
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
};


