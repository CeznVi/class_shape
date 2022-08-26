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
            cout << "� ��������� " << i << " ����� ����\n";
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
            cout << "� ��������� " << i << " ����� ����\n";
    }
    cout << "\n���� ��������� � ����\n";
}

void loadFromFile(Shape** arr, int SIZE)
{
    string name;
    ifstream fin;

    fin.open("shape.txt", ios::in);

    if (!fin)
    {
        std::cerr << "������� ������� �����...\n";
        exit(1);
    }

    if (fin.is_open())
    {
        int i{};
        while (fin)
        {
            fin >> name;
            if (name == "�������")
            {
                arr[i] = new Square{};
                arr[i]->Load(i);
            }
            else if (name == "�����������")
            {
                arr[i] = new Reactangle{};
                arr[i]->Load(i);
            }
            else if (name == "����")
            {
                arr[i] = new Circle{};
                arr[i]->Load(i);
            }
            else if (name == "����")
            {
                arr[i] = new Elipse{};
                arr[i]->Load(i);
            }
           i++;
           getline(fin, name);
            
        }
        cout << "\n���� ������ ����������� � �����\n";
    }    
    fin.close();
}