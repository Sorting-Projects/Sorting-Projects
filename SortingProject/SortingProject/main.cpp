#include<iostream>
#include "On2.h"
#include "Onlogn.h"
#include "DataGenerator.h"
using namespace std; 

int main()
{
    srand((unsigned int)time(NULL));

    int n, choice;

    cout << "Nhap n: ";
    cin >> n;

    cout << "\nChon loai du lieu:\n";
    cout << "0 - Random\n";
    cout << "1 - Sorted\n";
    cout << "2 - Reverse\n";
    cout << "3 - Nearly Sorted\n";
    cout << "4 - Tat ca cac loai\n";
    cout << "Nhap lua chon: ";
    cin >> choice;

    int* a = new int[n];

    if (choice >= 0 && choice <= 3)
    {
        GenerateData(a, n, choice);
        PrintArray(a, n);
    }
    else if (choice == 4)
    {
        for (int type = 0; type <= 3; type++)
        {
            cout << "\nLoai du lieu " << type << ":\n";
            GenerateData(a, n, type);
            PrintArray(a, n);
        }
    }
    else
    {
        cout << "Lua chon khong hop le!\n";
    }

    delete[] a;

    return 0;
}
