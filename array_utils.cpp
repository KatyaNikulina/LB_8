#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int array_71()
{
    cout << "\n=== Задание 1: Array ===\n";
    
    // Імена файлів
    string inputFilename = "array_in_71.txt";
    string outputFilename = "array_out_71.txt";

    // Відриваємо вхідной файл
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) 
    {
        cerr << "Error opening file " << inputFilename << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    // Перевірка на коректність розміру масиву
    if (N <= 0) 
    {
        cerr << "Incorrect array size: " << N << endl;
        inputFile.close();
        return 1;
    }

    // Читаемо елементи масиву
    vector<int> array(N);
    for (int i = 0; i < N; i++) 
    {
        if (!(inputFile >> array[i])) 
        {
            cerr << "Error reading array element with index " << i << endl;
            inputFile.close();
            return 1;
        }
    }

    // Закриваємо вхідний файл
    inputFile.close();

    // Змінюємо порядок елементів на зворотній
    reverse(array.begin(), array.end());

    // Відриваємо вихідний файл
    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) 
    {
        cerr << "Error opening file for writing " << outputFilename << endl;
        return 1;
    }

    // Записуємо розмір масиву
    outputFile << N << endl;

    // Записуємо елементи у зворотному порядку
    for (int i = 0; i < N; i++) 
    {
        outputFile << array[i];
        if (i < N - 1) 
        {
            outputFile << " ";
        }
    }
    outputFile << endl;

    // Зачиняємо вихідний файл
    outputFile.close();

    cout << "The array is written to the file in reverse order. " << outputFilename << endl;

    return 0;
}
