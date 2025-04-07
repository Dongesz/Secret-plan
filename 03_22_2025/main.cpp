#include <iostream>
#include <iomanip>
#include <string>

double addn(double a, double b){
    return a + b;
}
double subtractn(double a, double b){
    return a - b;
}
double multiplyn(double a, double b){
    return a * b;
}
double deviden(double a, double b){
    if (a==0||b==0) 
        return 0;
    else
        return a / b;
}
void menu(){
    int operation;
    double num1;
    double num2;
    while (true){
        std::cout << "Console Calculator - Made by Dongesz" << std::endl;
        std::cout << "1 - Add" << std::endl;
        std::cout << "2 - Subtract" << std::endl;
        std::cout << "3 - Multiply" << std::endl;
        std::cout << "4 - Devide" << std::endl;
        std::cout << "5 - exit" << std::endl;
        std::cout << "Choose between the operations!: ";
        std::cin >> operation;
        if (operation == 5) 
            std::cout << "See yaa!" << std::endl;
            break;
        std::cout << "Enter two number!: ";
        std::cin >> num1 >> num2;
        switch (operation){
        case  1:
            std::cout << "Result: " << addn(num1,num2) << std::endl;
            break;
        case 2:
            std::cout << "Result: " << subtractn(num1,num2) << std::endl;
            break;
        case 3:
            std::cout << "Result: " << multiplyn(num1,num2) << std::endl;
            break;
        case 4:
            if (deviden(num1,num2) == 0) std::cout << "Cannot devide by 0" << std::endl;
            else std::cout << "Result: " << deviden(num1,num2) << std::endl;    
            break;
        default:
            break;
        }
    }
}

int main(){
    menu();
}

