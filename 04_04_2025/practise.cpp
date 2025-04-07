#include <iostream>

int main(){
    //Writing into uninitialized pointer
    int *pNum1; // junk address
    //*pNum1 = 10; - writing into junk address is not recommended

    //Writing into a nullptr/pointer pointing nowhere
    int *pNum2{nullptr}; 
    //*pNum2 = 10; - writing into a pointer pointing nowhere is also not recommended, can cause CRASH!

    // Note to self: Always initialize pointers before you use them, dont use pointers if you dont know what they doing, dont try to work with a pointer pointing to nullptr!!!
    //Using Stack:

        { // creates var here (start of scope)
            int localScopeVar{10};
        } // deletes var here (end of scope)

    //Using the Heap(dynamic memory):
        
        int *pNum3{nullptr};
        pNum3 = new int; // Creates dynamically allocated memory for a single int on the heap, this memory belong to our program now, our system can use anything else untill we return it.
        *pNum3 = 10; // Writing into Dynamically allocated memory
        delete pNum3; // return memory to the system
        pNum3 = nullptr; // *nice practise to asign nullpr to the memory you just returned trough delete*

        //initialize with new upon declaration
        int *pNum5{new int(15)};
        int *pNum6{new int{15}};
        //release thew memory
        delete pNum5;
        pNum5 = nullptr;
        delete pNum6;
        pNum6 = nullptr;

        // Note to self: using delete twice on the same pointer is a BIG NO NO
}