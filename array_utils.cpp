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
    
    // Имена файлов
    string inputFilename = "array_in_71.txt";
    string outputFilename = "array_out_71.txt";

    // Открываем входной файл
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) 
    {
        cerr << "Ошибка открытия файла " << inputFilename << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    // Проверка на корректность размера массива
    if (N <= 0) 
    {
        cerr << "Некорректный размер массива: " << N << endl;
        inputFile.close();
        return 1;
    }

    // Читаем элементы массива
    vector<int> array(N);
    for (int i = 0; i < N; i++) 
    {
        if (!(inputFile >> array[i])) 
        {
            cerr << "Ошибка чтения элемента массива с индексом " << i << endl;
            inputFile.close();
            return 1;
        }
    }

    // Закрываем входной файл
    inputFile.close();

    // Меняем порядок элементов на обратный
    reverse(array.begin(), array.end());

    // Открываем выходной файл
    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) 
    {
        cerr << "Ошибка открытия файла для записи " << outputFilename << endl;
        return 1;
    }

    // Записываем размер массива
    outputFile << N << endl;

    // Записываем элементы в обратном порядке
    for (int i = 0; i < N; i++) 
    {
        outputFile << array[i];
        if (i < N - 1) 
        {
            outputFile << " "; // разделитель между элементами
        }
    }
    outputFile << endl;

    // Закрываем выходной файл
    outputFile.close();

    cout << "Массив в обратном порядке записан в файл " << outputFilename << endl;

    return 0;
}
