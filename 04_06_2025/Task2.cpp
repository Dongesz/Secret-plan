/*
    Task 2: Reference Parameter Practice

    Write a function called `increaseByTen(int& ref)` which:
    - Takes an int reference as a parameter.
    - Adds 10 to the original variable.

    In main():
    - Create an int variable.
    - Pass it to the function by reference.
    - Print it before and after the function call.

    Goal: Understand how passing by reference allows in-place modification without return.
*/

#include <iostream>
int increaseByTen(int &ref)
{
    ref += 10;
    return ref;
}
int main()
{
    int number = 10;
    std::cout << number << "\n";
    increaseByTen(number);
    std::cout << number << "\n";
}
