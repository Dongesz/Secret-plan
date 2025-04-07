#include <iostream>

int main(){
    bool x = true; // => 1
    bool y = false; // => 0

    std::cout << std::boolalpha; // forces true/false format
    std::cout << x << y << std::endl;

    if (!x) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    
    
}