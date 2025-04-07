/*
    Task 1: Nullptr Guard

    Create a function called `printValue(int* ptr)` which:
    - Checks if the pointer is a nullptr.
    - If it's a nullptr, prints "Invalid pointer!".
    - If it's valid, prints the integer value pointed to.

    In main(), create:
    - A valid dynamically allocated integer (e.g. new int(42)) and pass it to the function.
    - A nullptr and pass it to the function.

    Goal: Practice safe pointer validation using simple conditional logic.
*/
#include <iostream>

int printValue(int *ptr)
{
    if (!ptr)
    {
        std::cout << "Invalid pointer!" << "\n";
        return 0;
    }

    else
    {
        std::cout << *ptr << "\n";
        return 0;
    }
}

int main()
{
    int *test1{new int{32}};
    int *test2{nullptr};
    printValue(test1); // "32"
    printValue(test2); // "Invalid pointer!"

    // Todays lesson, return after you done!
    delete test1;
    test1 = nullptr;
    delete test2;
    test2 = nullptr;
}
