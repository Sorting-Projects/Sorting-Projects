#include <iostream>
#include <string>
#include <fstream>
#include "output.h"
using namespace std;

int main(int argc, char* argv[])
{

    cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; i++)
        cout << "argv[" << i << "] = [" << argv[i] << "]" << endl;

    if (argc <= 2)
    {
        cout << "Error: Invalid arguments!" << endl;
        return 0;
    }

    if (string(argv[1]) == "-a")
    {
        bool check = algorithmMode(argc, argv);
        if (check == false)
        {
            cout << "Error: Invalid arguments!" << endl;
        }
    }
    else if (string(argv[1]) == "-c")
    {
        bool check = comparisonMode(argc, argv);
        if (check == false)
        {
            cout << "Error: Invalid arguments!" << endl;
        }
    }
    else
    {
        cout << "Error: Invalid arguments!" << endl;
    }

    return 0;
}