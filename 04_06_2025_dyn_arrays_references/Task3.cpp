/*
    Task 3: Const Reference vs Pointer Swap

    Step 1:
    - Create two int variables.
    - Pass them to a `void swapValues(int* a, int* b)` function using pointers.
    - Inside, swap the values using a temporary variable and dereferencing.

    Step 2:
    - Try creating a swap function using const references.
    - Observe and explain why it fails to modify the values.

    Goal: Understand mutability differences between pointers and const references.
    Bonus: Learn when and why not to use const reference when mutation is needed.
*/

#include <iostream>
void swapValuesptr(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    std::cout << "PointerSwap: " << *a << " " << *b << "\n";
}
/*
void swapValuesconstref(const int &a, const int &b){ 
    int tmp = a;
    a = b;
    b = tmp;
    Error: expression must be a modifiable lvalueC/C++(137)
    Cannot write into const vars, this way you cant swap them!
}*/
void swapValuesref(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    std::cout << "Swap by ref: " << a << " " << b << "\n";
}
int main()
{
    int a = 5;
    int b = 1;
    std::cout<< "Original: " << a << " " << b << "\n";
    swapValuesptr(&a, &b);
    // const int &refa{a};
    // const int &refb{b};
    // swapValuesref(refa,refb);
    int &refa{a};
    int &refb{b};
    swapValuesref(refa, refb);
}
