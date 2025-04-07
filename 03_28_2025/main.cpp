#include <iomanip>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <fstream>
#include <filesystem>
#include <ranges>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
const int Rows = 5;
const int Cols = 5;

void showSeating(string array[Rows][Cols]){ //works fine
    cout << endl;
    cout << setw(3) << '1'<< setw(3) << '2'<< setw(3) << '3'<< setw(3)<< '4'<< setw(3) << '5';
    for (int x = 0; x != Rows; x++){ 
        cout << endl ;
        cout << x+1;
        for (int y = 0; y != Cols ; y++){ 
            cout << array[x][y];
        } 
    }
    cout << endl;
}
void updateSeating(string array[Rows][Cols], int x, int y){ //works fine
    array[x-1][y-1] = "[x]";
}
void deleteSeating(string array[Rows][Cols], int x, int y){ //works fine
    array[x-1][y-1] = "[ ]";
}
std::ofstream CreateSeatingFile() { //work fine
    if (!std::filesystem::exists("seating.txt")) {
        std::ofstream file("seating.txt");
        return file;
    }
    return std::ofstream();  
}
void saveSeating(string array[Rows][Cols], std::ofstream& file){ //works fine
    if (file.is_open())
    {
        for (int x = 0; x != Rows; x++){ 
            for (int y = 0; y != Cols ; y++){ 
                file << array[x][y]+',';
            } 
            file << endl;
        }
    }
}
void loadSeating(string array[Rows][Cols]){ //works fine
    ifstream file("seating.txt");
    string line;
    int row = 0;
    while (getline(file, line) && row < Rows) {
        istringstream iss(line);
        string token;
        int col = 0;
        while (getline(iss, token, ',') && col < Cols) {
            array[row][col] = token;
            col++;
        }
        row++;
    }
    file.close();
}
void setColor(int textColor){ //works fine
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}
void showMenu(string array[Rows][Cols]){ //work fine
    loadSeating(array);
    setColor(14);
    cout << "Theater Seat Reservation System! - by dongesz" << endl;
    while (true){
        setColor(10);
        cout << "1 - Reserve Seat!" << endl;
        setColor(12);
        cout << "2 - Cancel Reservation!" << endl;
        setColor(7);
        cout << "3 - Show Seating Plan! " << endl;
        setColor(11);
        cout << "5 - Exit!" << endl;
        setColor(7);
        int c;
        cin >> c;
        if (c == 5){
            setColor(7);
            cout << "Program closed, see you next time!" << endl;
            break;
        }
        else{
            int x, y;
            switch (c){
            case 1:{
                cout << "Please enter which seat you would like to reserve!(Rows, Columns): ";
                cin >> x >> y;
                if (x > Rows || y > Cols){
                    setColor(12);
                    cout << "\nYour seat must be in the [5;5] range, try again!\n\n";
                }
                else{
                    if (array[x-1][y-1] != "[ ]" ){
                        setColor(12);
                        cout << "\nThis seat is already taken!\n\n";
                    }
                    else{
                        updateSeating(array,x,y);
                        setColor(10);
                        cout << "\nSuccessful reservation!\n\n";
                    }
                }
                break;
            }
            case 2:{
                cout << "Please enter which seat you would like to cancel!(Rows, Columns): ";
                cin >> x >> y;
                if (array[x-1][y-1] == "[ ]"){
                    setColor(12);
                    cout << "\nThis seat is already empty!\n\n";
                }
                else{
                    deleteSeating(array,x,y);
                    setColor(10);
                    cout << "\nSuccessful cancellation!\n\n";
                }
                break;
            }
            case 3:{
                showSeating(array);
                cout << endl;
                break;
            }
            default:{
                setColor(12);
                cout << "\nInvalid option, try again!\n\n";
                break;
            }
        }
        ofstream file = CreateSeatingFile();
        file.open("seating.txt");
        if (file.is_open()) {
            saveSeating(array, file);
            file.close();
            setColor(10);
            cout << "\nSeating plan saved successfully!\n\n";
        } 
        else {
            setColor(12);
            cout << "\nFailed to save seating plan!\n\n";
        }
        }
    }
}

int main(){
    string seating[5][5] = {
        {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}, //x >
        {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
        {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
        {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
        {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}  //y v
    }; 
   showMenu(seating);
}