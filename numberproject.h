// ENUMS, CONST, DEFINE
#define ARRAY_LENGTH 1000
#define FILE_NAME "numbers.txt"

void viewNumbers();
void generateRandomNumbersFunction();
int* generateRandomNumber(int seed, int m, int n, int y, int* array);

// Classes 
class Numbers
{
public:
    // Getters
    int *getNumbersArray(){
        return numbersArray;
    }

    // View Number Functions
    void viewAllNumbers();
    void viewLastThreeNumbers();
    void viewAllEvenNumbers();
    void viewAllOddNumbers();

    // Random Number Game Functions
    void randomNumberGame();



private:
    int numbersArray[ARRAY_LENGTH];
};


// Structs

