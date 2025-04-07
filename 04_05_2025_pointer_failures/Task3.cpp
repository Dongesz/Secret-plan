/*
    Task 3: Dangling Hydra

    Create a pointer `master` pointing to a dynamically allocated int.
    Create two more pointers (`slave1`, `slave2`) that also point to the same memory.

    Then:
    - Delete `master` and set it to nullptr.
    - Before accessing any slave pointer, always check whether the master is valid.
    - Only allow access to slave pointers if the master is not nullptr.

    Also: write separate functions for printing master, slave1, and slave2
    that first check the master's validity before dereferencing any pointer.

    Goal: Understand and prevent dangling pointer behavior when multiple pointers
    share the same target.
*/
#include <iostream>

int showPtr(int *slave, int *master)
{
    if (master)
    {
        std::cout << "Master is valid!" << "\n"
                  << *slave << "\n";
    }
    else
    {
        std::cout << "Master is not valid!" << "\n";
    }
    return 0;
}

int main()
{
    int *master{new (std::nothrow) int{10}};
    int *slave1 = master;
    int *slave2 = master;

    showPtr(slave1, master);
    showPtr(slave2, master);

    delete master;
    master = nullptr;

    showPtr(slave1, master);
    showPtr(slave2, master);

    slave1 = nullptr;
    slave2 = nullptr;
}
