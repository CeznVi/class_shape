#pragma once


void print(Shape** arr, int SIZE)
{
    for (int i{}; i < SIZE; i++)
    {
        if (arr[i])
        {
            cout << "----------\n";
            arr[i]->Show();
        }
        else 
            cout << "В покажчику " << i << " даних немає\n";
    }



}

void clearFile()
{
    ofstream fout;
    fout.open("shape.txt", ios::trunc);
    fout.close();
}

void saveToFile(Shape** arr, int SIZE)
{
    for (int i{}; i < SIZE; i++)
    {
        if (arr[i])
        {
            arr[i]->Save();
        }
        else
            cout << "В покажчику " << i << " даних немає\n";
    }
    cout << "\nДанні збережено у файл\n";
}

void loadFromFile(Shape** arr, int SIZE)
{
    string name;
    ifstream fin;

    fin.open("shape.txt", ios::in);

    if (!fin)
    {
        std::cerr << "Помилка читання файлу...\n";
        exit(1);
    }

    if (fin.is_open())
    {
        int i{};
        while (fin)
        {
            fin >> name;
            if (name == "Квадрат")
            {
                arr[i] = new Square{};
                arr[i]->Load(i);
            }
            else if (name == "Прямокутник")
            {
                arr[i] = new Reactangle{};
                arr[i]->Load(i);
            }
            else if (name == "Коло")
            {
                arr[i] = new Circle{};
                arr[i]->Load(i);
            }
            else if (name == "Еліпс")
            {
                arr[i] = new Elipse{};
                arr[i]->Load(i);
            }
           i++;
           getline(fin, name);
            
        }
        cout << "\nДанні успішно завантажено з файлу\n";
    }    
    fin.close();
}