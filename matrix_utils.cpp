#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <string>
#include <limits>

using namespace std;

int matrix_36()
{
    cout << "\n=== Задание 2: Matrix36 ===\n";

    // Имена файлов
    string filename = "matr_in_36.txt";

    // Открываем файл для чтения
    ifstream inputFile(filename);
    if (!inputFile.is_open()) 
    {
        cerr << "Ошибка открытия файла " << filename << endl;
        return 1;
    }

    // Читаем размер матрицы
    int M_1, N_1;
    inputFile >> M_1 >> N_1;

    if (M_1 <= 0 || N_1 <= 0)
    {
        cerr << "Ошибка: M и N должны быть положительными числами!\n";
        inputFile.close();
        return 1;
    }

    // Читаем элементы матрицы
    vector<vector<int>> matrix(M_1, vector<int>(N_1));
    for (int i = 0; i < M_1; ++i)
    {
        for (int j = 0; j < N_1; ++j)
        {
            if (!(inputFile >> matrix[i][j]))
            {
                cerr << "Ошибка чтения элемента матрицы [" << i << "][" << j << "]" << endl;
                inputFile.close();
                return 1;
            }

            if (matrix[i][j] < 0 || matrix[i][j] > 100)
            {
                cerr << "Число в позиции [" << i << "][" << j << "] не входит в диапазон от 0 до 100!" << endl;
                inputFile.close();
                return 1;
            }
        }
    }

    // Закрываем входной файл
    inputFile.close();

    if (matrix.empty())
    {
        cout << "Матрица пуста!\n";
        return 1;
    }

    // Создаем множество элементов первой строки
    unordered_set<int> firstRowSet(matrix[0].begin(), matrix[0].end());
    int count = 0;

    // Сравниваем начиная со второй строки (индекс 1)
    for (size_t i = 1; i < matrix.size(); ++i)
    {
        unordered_set<int> currentRowSet(matrix[i].begin(), matrix[i].end());
        if (currentRowSet == firstRowSet)
        {
            count++;
        }
    }

    // Открываем тот же файл для дозаписи
    ofstream outputFile(filename, ios::app);
    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла для записи " << filename << endl;
        return 1;
    }

    // Дописываем результат в конец файла
    outputFile << "\nКоличество строк, похожих на первую: " << count << endl;

    // Закрываем выходной файл
    outputFile.close();

    cout << "Количество строк, похожих на первую: " << count << "\n";
    cout << "Результат дописан в тот же файл " << filename << endl;

    return 0;
}
