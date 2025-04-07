#include <iostream>
#include <array>
using namespace std;

void swaap(int *a, int *b)
{
    cout << "Original: " << "\nNum1: " << *a << "\nNum2: " << *b << endl;
    int tmp{*a};
    *a = *b;
    *b = tmp;
    cout << "Swapped Successfully!" << endl;
}

void toUptper(char *input)
{
    char *str{input};
    while (*str != '\0')
    {
        *str = toupper(*str);
        cout << *str;
        str++;
    }
}

void reverseArray(int *array, int size)
{
    int *left{array};
    int *right{&array[size - 1]};
    while (left < right)
    {
        int tmp{*left};
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int main()
{
    int num1 = 10;
    int num2 = 20;
    swaap(&num1, &num2);
    cout << "Test: " << "\nNum1: " << num1 << "\nNum2: " << num2 << endl;
    int *pNum1{&num1};
    int *pNum2{&num2};
    swaap(pNum1, pNum2);
    cout << "Final Test: " << "\nNum1: " << num1 << "\nNum2: " << num2 << endl;

    char input[]{"Ez a sablon peldaszoveg"};
    toUptper(input);
    cout << endl;

    int nums[]{1, 2, 3, 4, 5};
    cout << "Original array:" << endl;
    for (int element : nums)
    {
        cout << element << " ";
    }
    cout << endl;
    reverseArray(nums, size(nums));
    cout << "Reversed array: " << endl;
    for (int element : nums)
    {
        cout << element << " ";
    }
}