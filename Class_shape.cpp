#include <iostream>
#include <string>
#include<Windows.h>
#include "shape.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Тест\n";
    Shape* s;
    Square sq{10, 5, 12};
    
    s = &sq;
    s->Show();
    s->Save();

    return 0;
}
