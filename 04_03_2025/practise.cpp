#include <iostream>
using namespace std;

int main()
{
    int num{35};
    // A pointers used to store an adress an object its pointing at
    int *pNum{&num}; // Declares a pointer thats point to the var "num"

    // You can access an objects address by using & and their value by using * through a pointer
    cout << &num << "\n"
         << *pNum << endl;

    // You can only use pointers on the same type of object as your pointer
    double num2{35};
    // int* pNum2{&num2}; // error
    double *pNum2{&num2};

    // You can also declare an empty pointer called "nullpointer", but you have to do it the right way!!!
    int *pNum3{nullptr}; // right way - its set to adress zero
    int *pNum4{};        // big no no - its set to a random adress

    cout << &pNum3 << "\n"
         << &pNum4 << endl;

    // You can also move pointers
    pNum3++; // if you move it like this its gonna move it by the size of the object it points to
    pNum3--;

    // You can also use pointers to point at arrays
    int nums[5]{1, 2, 3, 4, 5};

    int *pNums{nums};       // If you point at an array you must leave the "&" otherwise its gonna cause a compiler error
    cout << *pNums << "\n"; // Printing out the pointers value gonna give the arrays first element

    // Char pointer, follows the same logic
    char welcome[]{"Welcome!"};
    char *pWelcome{welcome};   // no "&"
    cout << *pWelcome << endl; // prints out he first element - "W"

    // You can also use pointers to point at pointers
    char *pWelcome2{pWelcome}; // if you point at a pointer, its values gonna be the value of the object thats the original pointers point at
    cout << *pWelcome2;        // "W"

    // There are also Void, and function pointers, but they area  bit too complex for me right now
}