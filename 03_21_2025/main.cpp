#include <iostream>
#include <string>

int main(){
    // typename varname {value}

    // Same number in different numeral systems
    int num1 = 15; // Deciaml
    int num2 = 017; // Octal
    int num3 = 0x0f; // Hexadecimal
    int num4 = 0b00001111; // Binary

    // All 3 does the same, initialize 15 to the variable!
    int num5{15}; // Braced initialization : "{}"
    int num6(15); // Functional initialization : "()"
    int num7 = 15; // Assignment notation : "="

     // Var initialized this way may contain random/garbage value!!!
     int num8;
     int num9{}; // 0 value by default

     // Usefull for clear code
     signed int num10{-15}; // both pos/neg value - Default
     unsigned int num11{15}; // only pos value
     
     //Only on int!!!
     short num12{15}; // 2 Byte
     int num13{15}; // 4 Byte
     long num14{15}; // 4 or 8 Byte

     // You can also combine 
     short int num15{15}; // 2 Byte
     long int num16{15}; // 4 Byte
     long long num17{15}; // 8 Byte

    std::cout << num1 <<" " << num2 <<" " << num3 << " " <<  num4 << " " << num5 << " " << num6 << " " << num7<< std::endl; // => 15 15 15 15 15 15 15
    std::cout << sizeof(num4) << std::endl; // returns parameter size
    std::cout << num10 << " " <<  num11 << std::endl;// => -15 15
    std::cout << sizeof(num12) << " " << sizeof(num13) << " " << sizeof(num14) << std::endl; // => 2 4 4
    std::cout << sizeof(num15) << " " << sizeof(num16) << " " << sizeof(num17) << std::endl; // => 2 4 8
    
} 