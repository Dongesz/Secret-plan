#include <iostream>
using namespace std;

void testMemoryLeak(){ // This code runs without a compiler error, but has a memory leak!!!
    for (int i = 0; i < 5; i++)
    {
        int *num = new int;
        *num = i*10;
    }
        
}

void testMemoryLeakFix(){ // Solved memory leak, now the function works fine!
    for (int i = 0; i < 5; i++)
    {
        int *num =  new int;
        *num = i*10;
        delete num;
        num = nullptr;
    }
    
}

int main(){
    // testMemoryLeak(); not gonna call this due to the memory leak!
    testMemoryLeakFix(); // works fine, you can call it any time!
}