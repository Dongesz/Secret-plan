#include <iostream>
#include <array>
#include <cctype>
std::string toLowercase(std::string word)
{
    std::string lowercaseWord = word;
    for (int i = 0; i < std::size(word); i++)
        lowercaseWord[i] = tolower(word[i]);
    return lowercaseWord;
}
void containsAtLeast5(std::string pass, int &current_level)
{
    if (std::size(pass) >= 5)
    {
        std::cout << "lvl" << current_level << " - completed!" << "\n";
        current_level++;
        return;
    }
    std::cout << "Password must be at least 5 characters!" << "\n";
}
void containsDigit(std::string pass, int &current_level)
{
    for (int i = 0; i < std::size(pass); i++)
    {
        if (isdigit(pass[i]))
        {
            std::cout << "lvl" << current_level << " - completed!" << "\n";
            current_level++;
            return;
        }
    }
    std::cout << "Password must contain a number!" << "\n";
}
void containsUpper(std::string pass, int &current_level)
{
    for (int i = 0; i < std::size(pass); i++)
    {
        if (isupper(pass[i]))
        {
            std::cout << "lvl" << current_level << " - completed!" << "\n";
            current_level++;
            return;
        }
    }
    std::cout << "Passwort must contain an Uppercase character!" << "\n";
}
void containsSymbol(std::string pass, int &current_level)
{
    for (int i = 0; i < std::size(pass); i++)
    {
        if (ispunct(pass[i]))
        {
            std::cout << "lvl" << current_level << " - completed!" << "\n";
            current_level++;
            return;
        }
    }
    std::cout << "Password must contain a symbol!" << "\n";
}
void mainMenu()
{
    while (true)
    {
        std::string password{};
        std::cout << "Enter a password!: " << "\n";
        std::cin >> password;
        int current_level = 1;
        int &current_level_ref = current_level;
        int max_level = 4;
        if (password == toLowercase("EXIT"))
        {
            std::cout << "Program closed, see you next time!" << "\n";
            return;
        }
        containsAtLeast5(password, current_level);
        containsDigit(password, current_level);
        containsUpper(password, current_level);
        containsSymbol(password, current_level);
        if (current_level == max_level)
        {
            std::cout << "You Won!" << "\n";
            return;
        }
    }
}
int main()
{
    mainMenu();
}