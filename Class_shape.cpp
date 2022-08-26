#include <iostream>
#include <string>
#include<Windows.h>
#include "shape.h"
#include "func.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    //розмір масиву
    const int SIZE = 4;

    //Cтворюємо фігури
    Square sq{ 22, 4, 30 };
    Reactangle react{ 5,8,15,5 };
    Circle circl{ 122, 34, 20 };
    Elipse elips{ 0, 0, 13, 8};
     
    Shape* arrShape[SIZE]{};
       
    arrShape[0] = &sq;
    arrShape[1] = &react;
    arrShape[2] = &circl;
    arrShape[3] = &elips;

   //роздрукувати
   print(arrShape, SIZE);
   //очистити файл
   clearFile();
   //зберегти все в файл
   saveToFile(arrShape, SIZE);
   
   system("pause");
   system("cls");

   Shape* arrShape2[SIZE]{};
   cout << "Завантаження даних із файлу у другий масив\n";
   //Завантажити із файлу до масиву
   loadFromFile(arrShape2, SIZE);
   
   print(arrShape2, SIZE);

   return 0;
}


