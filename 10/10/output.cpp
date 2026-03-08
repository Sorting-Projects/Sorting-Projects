#include "output.h"


const int sz = 1e6 + 5;

int A[sz];
int B[sz];

int getSortName(const string& sortName)
{
    if (sortName == "selection-sort") return 0;
    if (sortName == "insertion-sort") return 1;
    if (sortName == "shell-sort") return 2;
    if (sortName == "bubble-sort") return 3;
    if (sortName == "heap-sort") return 4;
    if (sortName == "merge-sort") return 5;
    if (sortName == "quick-sort") return 6;
    if (sortName == "radix-sort") return 7;
    if (sortName == "counting-sort") return 8;
    if (sortName == "binary-insertion-sort") return 9;
    if (sortName == "shaker-sort") return 10;
    if (sortName == "flash-sort") return 11;

    return -1;
}

int getInputOrder(const string& inputOrder)
{
    if (inputOrder == "-rand") return 0;
    if (inputOrder == "-nsorted") return 1;
    if (inputOrder == "-rev") return 3;
    if (inputOrder == "-sorted") return 2;

    return -1;
}

int getOutputParameter(const string& outputParameter)
{
    if (outputParameter == "-time") return 1;
    if (outputParameter == "-comp") return 2;
    if (outputParameter == "-both") return 3;

    return -1;
}

void outputRuntime(int a[], int inputSize, const string& sortName, int command) {
    if (command == 0) cout << "Running time: ";
    else cout << " | ";

    switch (getSortName(sortName)) {
    case 0:
        cout << runTimeFunction(SelectionSort, a, inputSize);
        break;
    case 1:
        cout << runTimeFunction(InsertionSort, a, inputSize);
        break;
    case 2:
        cout << runTimeFunction(ShellSort, a, inputSize);
        break;
    case 3:
        cout << runTimeFunction(BubbleSort, a, inputSize);
        break;
    case 4:
        cout << runTimeFunction(HeapSort, a, inputSize);
        break;
    case 5:
        cout << runTimeFunction(MergeSort, a, inputSize);
        break;
    case 6:
        cout << runTimeFunction(QuickSort, a, inputSize);
        break;
    case 7:
        cout << runTimeFunction(RadixSort, a, inputSize);
        break;
    case 8:
        cout << runTimeFunction(CountingSort, a, inputSize);
        break;
    case 9:
        cout << runTimeFunction(BinaryInsertionSort, a, inputSize);
        break;
    case 10:
        cout << runTimeFunction(ShakerSort, a, inputSize);
        break;
    case 11:
        cout << runTimeFunction(FlashSort, a, inputSize);
        break;
    default:
        break;
    }
    cout << endl;
}


void outputComparisons(int a[], int inputSize, const string& sortName, int command) {
    if (command == 0) cout << "Comparison: ";
    else cout << " | ";

    long long count_compare = 0;
    switch (getSortName(sortName)) {
    case 0:
        SelectionSortwithComparison(a, inputSize, count_compare);
        break;
    case 1:
        InsertionSortwithComparison(a, inputSize, count_compare);
        break;
    case 2:
        ShellSortwithComparison(a, inputSize, count_compare);
        break;
    case 3:
        BubbleSortwithComparison(a, inputSize, count_compare);
        break;
    case 4:
        HeapSortwithComparison(a, inputSize, count_compare);
        break;
    case 5:
        MergeSortwithComparison(a, 0, inputSize - 1, count_compare);
        break;
    case 6:
        QuickSortwithComparison(a, 0, inputSize - 1, count_compare);
        break;
    case 7:
        RadixSortwithComparison(a, inputSize, count_compare);
        break;
    case 8:
        CountingSortwithComparison(a, inputSize, count_compare);
        break;
    case 9:
        BinaryInsertionSortwithComparison(a, inputSize, count_compare);
        break;
    case 10:
        ShakerSortwithComparison(a, inputSize, count_compare);
        break;
    case 11:
        FlashSortwithComparison(a, inputSize, count_compare);
        break;
    default:
        break;
    }

    cout << count_compare;
    if (command != 0)
        cout << endl;
}

void outputArray(const std::string& filePath, int a[], int inputSize) {
    ofstream fout(filePath);
    if (!fout.is_open()) {
        return;
    }
    fout << inputSize << endl;
    for (int i = 0; i < inputSize; i++) {
        fout << a[i] << " ";
    }

    fout << endl;
    fout.close();
}

void copyArray(int a[], int b[], int inputSize) {
    for (int i = 0; i < inputSize; i++) {
        a[i] = b[i];
    }

}


void outputParameter(int type, int a[], int inputSize, const string& sortName) {
    if (type == 1)
        outputRuntime(A, inputSize, sortName, 0);
    else if (type == 2)
        outputComparisons(A, inputSize, sortName, 0);
    else {
        outputRuntime(A, inputSize, sortName, 0);
        copyArray(A, B, inputSize);
        outputComparisons(A, inputSize, sortName, 0);

    }
}

bool algorithmMode(int argc, char* argv[]) {
    if (getSortName(argv[2]) == -1 || getOutputParameter(argv[argc - 1]) == -1)
        return false;

    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << Name[getSortName(argv[2])] << endl;

    if (argc == 5) {
        string filePath = string(argv[3]);
        if (filePath[0] >= '0' && filePath[0] <= '9') { // command 3
            int inputSize = stoi(filePath);
            if (inputSize > 1000000) return false;


            cout << "Input size: " << inputSize << endl;
            cout << endl;

            int type = getOutputParameter(string(argv[argc - 1]));
            if (type == -1) return false;
            int order[] = { 0, 3, 1, 2 };
            for (int i = 0; i < 4; i++) {
                cout << "Input order: " << DataOrder[i] << endl;
                cout << "-------------------------------------------" << endl;
                GenerateData(B, inputSize, order[i]);
                copyArray(A, B, inputSize);

                string digit = to_string(i + 1);
                outputArray("input_" + digit + ".txt", A, inputSize);
                outputParameter(type, A, inputSize, string(argv[2]));

                cout << endl;
            }
        }// command 3

        else { // command 1
            cout << "Input file: " << filePath << endl;
            ifstream fin(filePath);
            if (!fin.is_open()) return false;
            int inputSize = 0;
            fin >> inputSize;
            cout << inputSize << endl;

            cout << "Input size: " << inputSize << endl;

            for (int i = 0; i < inputSize; i++) {
                fin >> B[i];
            }

            copyArray(A, B, inputSize);

            int type = getOutputParameter(argv[argc - 1]);

            if (type == -1) return false;
            outputParameter(type, A, inputSize, string(argv[2]));
            outputArray("output.txt", A, inputSize);
        }

    }

    else if (argc == 6) { // command 2
        int inputSize = stoi(string(argv[3]).c_str());
        int typeOrder = getInputOrder(string(argv[4]));

        if (inputSize > 1000000 || typeOrder == -1)
            return false;

        cout << "Input size: " << inputSize << endl;
        cout << "Input order: " << DataOrder[typeOrder] << endl;

        

        cout << "-------------------------------------------" << endl;
        GenerateData(B, inputSize, typeOrder);
        copyArray(A, B, inputSize);

        outputArray("input.txt", A, inputSize);

        int type = getOutputParameter(string(argv[argc - 1]));

        if (type == -1)
            return false;

        outputParameter(type, A, inputSize, string(argv[2]));

        outputArray("output.txt", A, inputSize);
    }
    return true;
}

bool comparisonMode(int argc, char* argv[]) {
    if (getSortName(argv[2]) == -1 || getSortName(argv[3]) == -1) return false;
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: ";
    cout << Name[getSortName(argv[2])] << " | " << Name[getSortName(argv[3])] << endl;

    if (argc == 5) { // command 4
        string filePath = string(argv[argc - 1]);
        cout << "Input file: " << filePath << endl;
        ifstream fin(filePath);

        if (!fin.is_open()) return false;

        int inputSize = 0;
        fin >> inputSize;

        for (int i = 0; i < inputSize; i++) {
            fin >> B[i];
        }

        copyArray(A, B, inputSize);

        cout << "Input size: " << inputSize << endl;
        cout << "-------------------------------------------" << endl;

        outputRuntime(A, inputSize, argv[2], 0);

        copyArray(A, B, inputSize);
        outputRuntime(A, inputSize, argv[3], 1);

        copyArray(A, B, inputSize);
        outputComparisons(A, inputSize, argv[2], 0);

        copyArray(A, B, inputSize);
        outputComparisons(A, inputSize, argv[3], 1);

        fin.close();
    }
    else // command 5
    {
        int inputSize = stoi(string(argv[argc - 2]));
        int typeOrder = getInputOrder(string(argv[argc - 1]));

        if (inputSize > 1000000 || typeOrder == -1)
            return false;

        cout << "Input size: " << inputSize << endl;
        cout << "Input order: " << DataOrder[typeOrder] << endl;
        cout << "-------------------------------------------" << endl;

        GenerateData(B, inputSize, typeOrder);
        outputArray("input.txt", B, inputSize);

        copyArray(A, B, inputSize);
        outputRuntime(A, inputSize, argv[2], 0);

        copyArray(A, B, inputSize);
        outputRuntime(A, inputSize, argv[3], 1);

        copyArray(A, B, inputSize);
        outputComparisons(A, inputSize, argv[2], 0);

        copyArray(A, B, inputSize);
        outputComparisons(A, inputSize, argv[3], 1);
    }
    return true;


}
