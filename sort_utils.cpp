#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функція сортування вставками (зростання)
void insertionSort(vector<double>& arr) 
{
    for (size_t i = 1; i < arr.size(); ++i) 
    {
        double key = arr[i];
        int j = i - 1;

        // Зсуваємо елементи, більші за key, праворуч
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int sort_11() 
{

    cout << "\n=== Task 3: Sort11 ===\n";

    // Імена файлів
    string inputFilename = "sort_in_11.txt";
    string outputFilename = "sort_out_11.txt";

    // Зчитування з файлу
    ifstream input(inputFilename);
    vector<double> arr;
    double num;

    while (input >> num) 
    {
        arr.push_back(num);
    }
    input.close();

    // Сортування
    insertionSort(arr);

    // Запис у файл
    ofstream output(outputFilename);
    for (const auto& num : arr) {
        output << num << " ";
    }
    output.close();

    cout << "Sorting completed. Result in file " << outputFilename << endl;
    return 0;
}
