/*
 * File: main.cpp
 * Author: Máté
 * Date: 2025-03-20
 * Description:
 *   Simple C++ program to demonstrate input and output,
 *   function usage, and string handling.
 */

#include <iostream>
#include <string>

//function declarations
int sumn(int x , int y){
    int res = x + y;
    return res;
}
int mult(int x , int y){
    int res = x * y;
    return res;
}

int main(){
    // int declaration
    int age;
    // string declaration
    std::string firstn, lastn;
    // cout - output to the consol
    std::string full_name;

    std::cout << "Enter your Name: ";
    // cin - input from the console, you can also chain together inputs!
    std::cin  >> firstn >> lastn; 
    std::cout << "Enter your Age: ";
    std::cin >> age;
    std::cout << "My name is " << lastn << " "<< firstn << ", im "<< age << " years old"<<", im learning c++!" << std::endl; // My name is {lastn} {firstn}, im {age} years old, im learning c++!
    std::cout << full_name << std::endl;

    // function callbacks
    std::cout << sumn(43,2) << std::endl; // 43 + 2 = 45
    std::cout << mult(5,5) << std::endl; // 5 * 5 = 25 


    // input with spaces
    std::cout << "Enter your full Name!: ";
    std::getline(std::cin,full_name);
    std::cout << full_name << std::endl;

}