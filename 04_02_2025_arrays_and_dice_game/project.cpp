#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> roll_dice(int dice, int times)
{
    srand(time(0));
    vector<int> rolls(times);
    for (int i = 0; i < times; i++)
    {
        rolls[i] = rand() % dice + 1;
    }
    cout << endl << dice << " sided dice rolled " << times << " times!" << endl;
    return rolls;
}

int findOccurrenceCount(vector<int> array, int target)
{
    int occurrenceCount{};
    for (auto num : array)
    {
        if (num == target)
            occurrenceCount++;
    }
    cout << "Occurrences of " << target << ": " << occurrenceCount << endl;
    return occurrenceCount;
}
int main()
{
    int dice{};
    int timesRolled{};
    int target{};
    vector<int> rolls{};
    cout << "Dice game - by Dongesz" << endl;
    while (true)
    {
        int menuChoice{};
        cout << "\n1 - Roll a dice\n"
             << "2 - Exit\n";
        cin >> menuChoice;
        if (menuChoice == 2)
        {
            cout << "\nExited Program Sucessfully!";
            break;
        }
        else
        {
            switch (menuChoice)
            {
            case 1:
                cout << "\nDice: ";
                cin >> dice;
                cout << "Rolls: ";
                cin >> timesRolled;
                cout << "Target number: ";
                cin >> target;
                rolls = {roll_dice(dice, timesRolled)};
                findOccurrenceCount(rolls, target);
                break;
            default:
                cout << "Invalid Menu Option!";
                break;
            }
        }
    }
}
