#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <string>
#include <limits>

using namespace std;

int matrix_36()
{
    cout << "\n=== Task 2: Matrix36 ===\n";

    // Імена файлів
    string filename = "matr_in_36.txt";

    // Відкриваємо файл для читання
    ifstream inputFile(filename);
    if (!inputFile.is_open()) 
    {
        cerr << "Error opening file " << filename << endl;
        return 1;
    }

    // Читаємо розмір матриці
    int M_1, N_1;
    inputFile >> M_1 >> N_1;

    if (M_1 <= 0 || N_1 <= 0)
    {
        cerr << "Error: M and N must be positive numbers!\n";
        inputFile.close();
        return 1;
    }
   
    // Читаємо елементи матриці
    vector<vector<int>> matrix(M_1, vector<int>(N_1));
    for (int i = 0; i < M_1; ++i)
    {
        for (int j = 0; j < N_1; ++j)
        {
            if (!(inputFile >> matrix[i][j]))
            {
                cerr << "Error reading matrix element [" << i << "][" << j << "]" << endl;
                inputFile.close();
                return 1;
            }

            if (matrix[i][j] < 0 || matrix[i][j] > 100)
            {
                cerr << "The number at position [" << i << "][" << j << "] is not in the range from 0 to 100!" << endl;
                inputFile.close();
                return 1;
            }
        }
    }

    // Закриваємо вхідний файл
    inputFile.close();

    if (matrix.empty())
    {
        cout << "The matrix is ​​empty!\n";
        return 1;
    }

    // Створюємо множину елементів першої строки
    unordered_set<int> firstRowSet(matrix[0].begin(), matrix[0].end());
    int count = 0;

    // Зрівнюємо починаючи з другої строки
    for (size_t i = 1; i < matrix.size(); ++i)
    {
        unordered_set<int> currentRowSet(matrix[i].begin(), matrix[i].end());
        if (currentRowSet == firstRowSet)
        {
            count++;
        }
    }

    // Відкриваємо той же файл для дозапису
    ofstream outputFile(filename, ios::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing " << filename << endl;
        return 1;
    }

    // Дописуємо результат в кінці файлу
    outputFile << "\nNumber of lines similar to the first: " << count << endl;

    // Закриваемо вихідний файл
    outputFile.close();

    cout << "Number of lines similar to the first: " << count << "\n";
    cout << "Result appended to the same file " << filename << endl;

    return 0;
}
