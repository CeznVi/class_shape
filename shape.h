#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//абстрактний клас
class Shape
{
protected:
	string name = "no_name";
	int x{}, y{};
	string fileName = "shape.txt";

public:
	Shape() { cout << "Конструктор Shape\n"; }
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
};

//Клас Квадрат
class Square : public Shape
{
	//довжина сторони
	int a{};

public:
	Square() { name = "Квадрат"; }
	Square(int x, int y, int a) 
	{ 
		name = "Квадрат";
		this->x = x; 
		this->y = y;
		this->a = a;
	}
	~Square() {}
	virtual void Show() override;
	virtual void Save() override;
	virtual void Load() override;
	virtual int area() { return a * a; }
	virtual int perimeter() { return 4 * a; }
};

void Square::Show()
{
	cout << name << '\n';
	cout << "Координати верхнього лівого кута\n";
	cout << "X = " << x << '\n';
	cout << "Y = " << y << '\n';
	cout << "Довжина сторони = " << a << '\n';
	cout << "Площа = " << area() << '\n';
	cout << "Периметр = " << perimeter() << '\n';
}

void Square::Save()
{
	std::ofstream fout;
	fout.open(fileName, std::ios::app);

	if (!fout)
	{
		std::cerr << "Помилка збереження файлу...\n";
		exit(1);
	}

	fout << name << "\n";
	fout << x << "\n";
	fout << y << "\n";
	fout << a << "\n";
	
	fout.close();

}

void Square::Load()
{

}