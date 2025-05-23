#include <iostream>
#include "array_utils.h"
#include "matrix_utils.h"
#include "sort_utils.h"

using namespace std;
int main()
{
    int choice;

    do
    {
        cout << "\n Select task:\n" 
             << "1. Array71\n" 
             << "2. Matrix 36\n" 
             << "3. Sort11\n" 
             << "0. Exit\n" 
             << "Your choice: ";
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
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Incorrect choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
