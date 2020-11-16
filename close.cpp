#include <iostream>
#include <fstream>
using namespace std;

typedef int indexx;
int razmer;
int* table;
bool* ispolzov;

indexx myhash(int data);
void insertData(int data);

indexx myhash(int data) {
    return (data % razmer);
}

void insertData(int data) {
    indexx nol;
    nol = myhash(data);
    while (ispolzov[nol] && table[nol] != data)
        nol = (nol + 1) % razmer;
    if (!ispolzov[nol]) {
        ispolzov[nol] = true;
        table[nol] = data;
    }
}

    int main()
    {
        setlocale(LC_ALL, "Russian");
        int* a, count;
        cout << "Введите количество элементов : "; cin >> count;       
        cout << "Введите размер хеш-таблицы : "; cin >> razmer;
        a = new int[count];  table = new int[razmer]; ispolzov = new bool[razmer];
        for (int i = 0; i < razmer; i++) {
            table[i] = 0;
            ispolzov[i] = false;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "Введите элемент: ";
            cin >> a[i];
        }
        for (int i = 0; i < count; i++)
        {
            insertData(a[i]);
        }

        for (int i = 0; i < razmer; i++) 
        {
            cout << "Ключ: " << i << "  ||  "<< "Занятность: " << ispolzov[i] << " || " << "Значение: " << table[i] << endl;
        }
        system("pause");
        return 0;
    }
