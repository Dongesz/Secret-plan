#include <iostream>

int main()
{
    // Dynamic Arrays:

    size_t size = 10;                                               // Not const and still compiles
    double *pTest1{new (std::nothrow) double[size]};                // array with garbage values
    double *pTest2{new (std::nothrow) double[size]{}};              // all values initialized to zero
    double *pTest3{new (std::nothrow) double[size]{1, 2, 3, 4, 5}}; // allocating memory space for an array of size double vars,
                                                                    // the first 5 values of the array will be 1,2,3,4,5,
                                                                    // the rest will be initialized with zero
    if (pTest3)
    {
        // Youre able to print out dynamic arrays with both array access notation, or pointer arithmetic
        for (int i = 0; i < size; i++)
            std::cout << "| Array acces notation: " << pTest3[i] << " " << "| Pointer arithmetic: " << *(pTest3 + i) << " |" << "\n";
    }

    // Return memory with "delete[]"
    delete[] pTest1;
    delete[] pTest2;
    delete[] pTest3;

    // Setting the pointers back to nullptr
    pTest1 = nullptr;
    pTest2 = nullptr;
    pTest3 = nullptr;

    // Static vs Dynamic arrays

    int staticArr[5]{1, 2, 3, 4, 5};
    std::cout << "Static arrays std::size: " << std::size(staticArr) << "\n"; // 5
    std::cout << "Static array with 'forrange': ";
    for (int element : staticArr)
        std::cout << element << ","; // 1,2,3,4,5
    /*
    int *dynamicArr{new(std::nothrow)int[5]{1,2,3,4,5}};
    std::cout << "Dynamic arrays std::size: " << std::size(dynamicArr) << "\n"; // compiler error!
    std::cout<< "Dynamic array with 'forrange': ";
    for (int element : dynamicArr)// compiler error!
        std::cout<< element << ",";
    */

    // References:
    int originalNum{50};
    int &referenceNum{originalNum}; // reference to originalNum

    std::cout << "\n"
              << referenceNum << "\n";  // Cointains the same value as the var its referencing to - 50
    std::cout << &referenceNum << "\n"; // we can access the original numbers address trough the reference

    // References vs Pointers

    int originalNum2{55};
    int &referenceNum2{originalNum2};
    int *pNum2{&originalNum2};
    // Reading:
    std::cout << "Read with reference: " << referenceNum2 << "\n"; // No need to dereference == easier syntax
    std::cout << "Read with pointer: " << *pNum2 << "\n";
    // Writing:
    referenceNum2 = 15;
    *pNum2 = 15; // No need to dereference == easier syntax

    // Cant change what an existing reference refering to(Thats why we cant make uninitialized references)
    int newrefereceNum{59};
    referenceNum2 = newrefereceNum; // asigns the value, but its still referencing the originalNum var!!!
    std::cout << referenceNum2 << "\n";
    // Test
    if (&originalNum2 == &referenceNum2)
        std::cout << "Still the same address!: " << &originalNum2 << "\n"
                  << "Only the value changed!" << "\n"
                  << "Original:" << originalNum2 << "\n"
                  << "Reference: " << referenceNum2 << "\n";
    else
        std::cout << "Reference refering to a different location!" << "\n";
    // with pointers:
    pNum2 = &newrefereceNum;
    if (&originalNum2 == pNum2)
        std::cout << "Still the same address!: " << &originalNum2 << "\n"
                  << "Only the value changed!" << "\n"
                  << "Original:" << originalNum2 << "\n"
                  << "pointer: " << pNum2 << "\n";
    else
        std::cout << "Pointers pointing to a different location!" << "\n";

    int originalNm3{77};
    const int &constreferenceNum3{originalNm3};
    // Reading - Allowed
    std::cout << constreferenceNum3 << "\n";
    // Writing - Not allowed
    // constreferenceNum3 = 88;
}
