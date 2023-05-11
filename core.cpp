#include<iostream>
using namespace std;
#include "core.h"
#include "numberproject.h"

int main()
{
    int i = 0, selection;
    printHeader();

    do{
        printf("\n****************************************\n");
        printf("           **    Menu    **               \n");
        printf("1. View list of previous random numbers\n");
        printf("2. Generate Random Numbers\n");
        printf("3. Guessing game\n");
        printf("4. Check if number is even or odd\n");
        printf("5. Quit\n");
        printf("*****************************************\n\n");

        printf("Selection: ");
        cin >> selection;

        switch (selection)
        {
        case 1:
            viewNumbers();
            break;
        
        case 2:
            generateRandomNumbersFunction();
            break;

        case 3:
            /* code */
            break;
        
        case 4:
            /* code */
            break;
        
        case 5:
            i = 1;
            break;
        default:
            break;
        }
        
    } while (i != 1);
    
    printf("Good Bye Human!");
    return 0;
}