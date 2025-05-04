#include <iostream>
#include "array_utils.h"
#include "matrix_utils.h"
#include "sort_utils.h"

using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int choice;

    do
    {
        cout << "\nВыберите задание:\n"
            << "1. Array71\n"
            << "2. Matrix36\n"
            << "3. Sort11\n"
            << "0. Выход\n"
            << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            array_71();
            break;
        case 2:
            matrix_36();
            break;
        case 3:
            sort_11();
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор! Попробуйте еще раз.\n";
        }
    } while (choice != 0);

    return 0;
}
