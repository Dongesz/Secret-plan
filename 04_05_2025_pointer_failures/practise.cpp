#include <iostream>

int main()
{
    // 3 main occurrence of Dangling Pointers

    // First reffering to uninitialized pointer
    int *pNum1{};
    std::cout << *pNum1 << "\n";
    // Second reffering to deleted pointer
    int *pNum2{new int{35}};
    delete pNum2;
    std::cout << pNum2 << "\n";
    // Third reffering to a deleted pointer with an existing one
    int *pNum3{new int{55}};
    int *pNum4{pNum3};
    std::cout << pNum4 << "\n";

    // Solutions:
    // First - main keypoint -> always initialize with something
    int *pNum1{nullptr};
    if (pNum1 != nullptr)
        std::cout << pNum1 << "\n";
    // Second - main keypoint -> always set back to nullptr after return
    int *pNum2{new int{55}};
    delete pNum2;
    pNum2 = nullptr;
    if (pNum2 != nullptr)
        std::cout << pNum2 << "\n";
    // Third - main keypoint -> find the master pointer and only allow interaction with the servents if the master is valid
    int *pNum3{new int{55}};
    int *pNum4{pNum3};
    delete pNum3;
    pNum3 = nullptr;
    if (pNum3 != nullptr)
        std::cout << pNum4 << "\n";

    // When "new fails"

    int *problem1{new int[1000000000]}; // Overloading the heap

    for (int i = 0; i < 10000000000; i++) // Overloading the heap
        int *problem2{new int[10]};

    // Solution - 1
    try // trys to run the code whitin the scope
    {
        int *problem1{new int[1000000000]};
    }
    catch (const std::exception &e) // if its unable to do, it throws an exeption, then outputs it to the console
    {
        std::cerr << e.what() << '\n';
    }
    // Solution - 2
    for (int i = 0; i < 10000000000; i++)
        int *problem2{new (std::nothrow) int[10]}; // if new fails, it initializes pointer to nullptr

    // Nullptr Safety

    int *nullp{};
    if (nullp)                       // check if the pointer is nullptr(true if not, false if is!!!)
        std::cout << *nullp << "\n"; // only useing it if its not

    // Memory Leaks

    // Case1 - double allocation
    int *leak1{new int{55}};
    // not deleting/returning
    leak1 = new int{43}; // memory leak here! Lost access to the previously booked memory
                         // Case2 - leaving local scope before returning
    {
        int *leak2{new int{53}};
        // not deleting/returning
    } // memory leak here! Lost access to the previously booked memory
}
