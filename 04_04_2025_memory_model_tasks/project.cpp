#include <iostream>
using namespace std;

void safeAllocate(){
    int *pNum{nullptr};
    pNum = new int;
    *pNum = 42;
    cout << *pNum << endl;
    delete pNum;
    pNum = nullptr;
}

int createAndFillArray(int size){
    int *pArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        *(pArray+i) = i + 1;
        cout << *(pArray+i) << endl;
    }
    delete[] pArray;
    pArray = nullptr;
    return 0;
}

int main(){
    createAndFillArray(5);
}