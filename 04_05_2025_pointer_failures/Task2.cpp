/*
    Task 2: Controlled Allocation with std::nothrow

    Create a function `allocateIntArray(size_t size)` that:
    - Uses `new (std::nothrow)` to allocate an array of integers on the heap.
    - If the allocation fails, prints "Allocation failed!" and returns.
    - If successful:
        - Fills the array with values from 0 to size - 1.
        - Prints all values using pointer arithmetic.
        - Frees the memory with `delete[]`.

    Goal: Practice error-aware dynamic memory allocation and cleanup.
*/
#include <iostream>

int allocateIntArray(size_t size)
{
    int *pArr{new (std::nothrow) int[size]};
    if (!pArr)
    {
        std::cout << "Allocation failed!" << "\n";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            *(pArr + i) = i + 1;
            std::cout << *(pArr + i);
                }
    }
    delete[] pArr;
    pArr = nullptr;
    return 0;
}

int main()
{
    allocateIntArray(5);
}
