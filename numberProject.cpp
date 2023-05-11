#include "core.h"
#include "numberproject.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


// Functions
void Numbers::viewAllNumbers()
{
    ifstream numbersFile;
    numbersFile.open(FILE_NAME, ios::in);
    int i = 1, data;
    
    if (!numbersFile)
    {
        cout << "Error!" << "\n";
    } else
    {
        printf("\n");
        while (!numbersFile.eof())
        {
            numbersFile >> data;
            cout << i << ". "<< data << "\n";
            i++;
        }
        printf("\n");
    }
    
    numbersFile.close();
}

void Numbers::viewLastThreeNumbers()
{
    ifstream numbersFile;
    numbersFile.open(FILE_NAME, ios::in);
    int numbersArray[ARRAY_LENGTH];
    int i = 0, j, data;

    if (!numbersFile)
    {
        cout << "Error!" << "\n";
    } else
    {
        while (!numbersFile.eof())
        {
            numbersFile >> data;
            numbersArray[i] = data;
            i++;
        }
        printf("\n");
        for (j = 0; j < i; j++)
        {
            if (j == i - 3 || j == i - 2 || j == i - 1)
            {
                cout << i - j << ". " << numbersArray[j] << "\n";
            }
        }
        printf("\n");
    }
    numbersFile.close();
}

void Numbers::viewAllEvenNumbers()
{
    ifstream numbersFile;
    numbersFile.open(FILE_NAME, ios::in);
    int numbersArray[ARRAY_LENGTH];
    int i = 0, j, x = 0, data;

    if (!numbersFile)
    {
        cout << "Error!" << "\n";
    } else
    {
        while (!numbersFile.eof())
        {
            numbersFile >> data;
            numbersArray[i] = data;
            i++;
        }

        printf("\n");
        for (j = 0; j < i; j++)
        {
            if (numbersArray[j] % 2 == 0)
            {
                cout << x + 1 << ". " << numbersArray[j] << "\n";
                x++;
            }
        }
        printf("\n");
    }
    numbersFile.close();
}

void Numbers::viewAllOddNumbers()
{
    ifstream numbersFile;
    numbersFile.open(FILE_NAME, ios::in);
    int numbersArray[ARRAY_LENGTH];
    int i = 0, j, x = 0, data;

    if (!numbersFile)
    {
        cout << "Error!" << "\n";
    } else
    {
        while (!numbersFile.eof())
        {
            numbersFile >> data;
            numbersArray[i] = data;
            i++;
        }

        printf("\n");
        for (j = 0; j < i; j++)
        {
            if (numbersArray[j] % 2 != 0)
            {
                cout << x + 1 << ". " << numbersArray[j] << "\n";
                x++;
            }
        }
        printf("\n");
    }
    numbersFile.close();
}

// Random Number Game 

void Numbers::randomNumberGame()
{

};



void printHeader()
{
    cout << "\n";
    cout << "****************************************\n";
    cout << "*      Random Number Project (RNP)     *\n";
    cout << "*                By                    *\n";
    cout << "*            Josh Date                 *\n";
    cout << "****************************************\n";
};



// Clear the standard input buffer
void clearInputBuffer(void)
{
 // Discard all remaining char's from the standard input buffer:
 while (getchar() != '\n')
 {
 ; // do nothing!
 }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
 printf("<ENTER> to continue...");
 clearInputBuffer();
}

// Menu Functions

void viewNumbers()
{
    int selection;
    Numbers numberClass;

    printf("\nPlease Select An Option:\n");
    printf("1. View All Of The Numbers In The List\n");
    printf("2. View The Last Three Numbers In The List\n");
    printf("3. View All Of The Even Numbers In The List\n");
    printf("4. View All Of The Odd Numbers In The List\n");
    printf("5. Go Back\n\n");
    printf("Selection: ");

    cin >> selection;

    switch (selection)
    {
    case 1:
        numberClass.viewAllNumbers();
        suspend();
        clearInputBuffer();
        break;
    
    case 2:
        numberClass.viewLastThreeNumbers();
        suspend();
        clearInputBuffer();
        break;

    case 3:
        numberClass.viewAllEvenNumbers();
        suspend();
        clearInputBuffer();
        break;

    case 4:
        numberClass.viewAllOddNumbers();
        suspend();
        clearInputBuffer();
        break;

    case 5:
        break; 

    default:
        suspend();
        clearInputBuffer();
        break;
    }
};

void generateRandomNumbersFunction()
{
    int length, firstSelectedNumber, secondSelectedNumber, i;
    cout << "Please the amount of random numbers you want to generate from 1-100: "; 
    cin >> length;

    cout << "Please select a random number: ";
    cin >> firstSelectedNumber;

    cout << "Please select another random number: ";
    cin >> secondSelectedNumber;

     // Declaring an array to be allocated on the heap
    int* randomNumbersArray = new int[length]{0};

    generateRandomNumber(firstSelectedNumber, 25, length, secondSelectedNumber,randomNumbersArray);
    cout << "Thank you! Adding random numbers to the current list!\n";

    // Adding random numbers to the text file
    ofstream numbersFile;
    int data;
    numbersFile.open(FILE_NAME, ios_base::app);
    
    if (!numbersFile)
    {
        cout << "Error! Could Not Add Numbers To The List" << "\n";
    } else
    {
        while (i < length)
        {
            numbersFile << "\n" << randomNumbersArray[i];
            i++;
        }
    }
    
    numbersFile.close();
    delete randomNumbersArray;
    suspend();
    clearInputBuffer();
};


int* generateRandomNumber(int firstSelectedNumber, int m, int arrayLength, int secondSelectedNumber,  int* array)
{
    // Xn = (a * Xn-1 + b) % m (formula for the linear Congruential Generator)

    int i;
    for (i = 0; i < arrayLength; i++)
    {
        firstSelectedNumber = (6 * firstSelectedNumber - 1 + 18) % m;
        array[i] = firstSelectedNumber;
    }
    
    for (i = 0; i < arrayLength; i++)
    {
        cout << array[i] << " " << "\n";
    }

    return array;
};