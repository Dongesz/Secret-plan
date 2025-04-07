# include <iostream>

int main(){
    int result;
    int num1 = 5;
    int num2 = 10;
    //basic operation 
        //Add
        result = num1 + num2;
        //Subtract
        result = num1 - num2;
        //Multiply
        result = num1 * num2;
        //devide
        result = num1 / num2;
        //Modulus
        result = num2 % num1;
        result = 10;
    //Incrementation
        //postfix
        result++; 
        //prefix
        ++result; 
    //Decrementation
        result--;
        --result;
    //Compound operatiors
        result += 1; // +1
        result -= 1; // -1
        result *= 1; // *1
        result /= 1; // /1
        result %= 1; // %1
    //Relational Operators => returns bool value (0/1)
    //num1=5, num2=10
        num1 < num2; // 1 - true
        num1 <= num2; // 1 - true
        num1 == num2; // 0 - false
        num1 != num2; // 1 - true
    //Logical operators => returns bool value, only works on bool values
        bool x = true;
        bool y = false;
        //And - all of them
        x && y ; // - false
        //Or - at least one of them
        x || y; // - true
        //Not - Negates the value
        !x; // - false
    
    
    

    
}