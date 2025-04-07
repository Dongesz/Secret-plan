/*
    Task 1: Dynamic Array Tools

    Create a function called `fillAndPrintArray` that:
    - Accepts a size_t parameter (array size).
    - Dynamically allocates an int array of the given size using std::nothrow.
    - Fills it with the values 1 to size using pointer arithmetic.
    - Prints all values using array access notation.
    - Frees the memory with delete[] and sets the pointer to nullptr.

    Goal: Practise pointer arithmetic, dynamic memory allocation, and safe cleanup.
*/

#include <iostream>

int fillAndPrintArray(size_t size)
{
    int *array{new (std::nothrow) int[size]};
    for (int i = 0; i < size; i++)
    {
        *(array + i) = i + 1;
        std::cout << *(array + i) << "\n";
    }
    delete[] array;
    array = nullptr;
    return 0;
}

int main()
{
    fillAndPrintArray(10);
}
