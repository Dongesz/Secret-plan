#include <iostream>
#include <array>
#include <string>
using namespace std;

int main()
{
    int nums[10];
    int sum{};
    for (int i{}; i < size(nums); i++)
    {
        nums[i] = i + 5;
        cout << "array element: " << i << " value: " << nums[i] << endl;
        sum += nums[i];
    }
    cout << "array count: " << size(nums) << endl;
    cout << "sum of array: " << sum << endl;

    // Ranged based for loop, loops trough a given container
    for (auto number : nums)
    {
        cout << number << endl;
    }
    // Oldschool way of figuring out size of a container
    int count{sizeof(nums) / sizeof(nums[0])};
    cout << count << " = " << size(nums) << endl;

    // Not optimal way to print strings
    char msg1[]{'a', 's', 'd', '\0'};
    cout << msg1 << endl;

    char msg2[4]{'a', 's', 'd'};
    cout << msg2 << endl;

    // Optimal way - string literal
    char msg3[]{"asd"};
    cout << "String literal(charstring): " << msg3 << endl;

    string msg4{"asd"};
    cout << "String library: " << msg4 << endl;
}