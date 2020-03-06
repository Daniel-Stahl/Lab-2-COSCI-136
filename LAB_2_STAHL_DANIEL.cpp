// LAB2 STAHL, DANIEL T TH

#include <iostream>
#include <string>

using namespace std;

void PresentMainMenu();
double RaiseNumberToPower(int num, int pow);
int SumOfSquaresAscending(int terms);
int SumOfSquaresDescending(int terms);
void RunRaisePowerMenu();
void RunAscendingMenu();
void RunDescendingMenu();

int main() {
    PresentMainMenu();
}

void PresentMainMenu() {
    int userChoice = 0;
    
    while (userChoice != 4) {
        cout << "Main Menu\n" << "1. Raise the power of a number\n" << "2. Sum of squares ascending\n" << "3. Sum of squares descending\n" << "4. Quit program\n";
        
        cin >> userChoice;
        cout << "\n";
        
        if (!cin || userChoice < 1 || userChoice > 4) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "That is not a valid selection, please try again.\n";
        } else {
            
            switch (userChoice) {
                case 1:
                    RunRaisePowerMenu();
                    
                    break;
                case 2:
                    RunAscendingMenu();
                    
                    break;
                case 3:
                    RunDescendingMenu();
                    
                    break;
            }
        }
    };
}

double RaiseNumberToPower(double num, int pow) {
    if (num == 0 && pow < 0) {
        cout << "Undefined, can't divide by ";
        return 0;
    } else if (pow == 0) {
        return 1;
    } else if (pow < 0) {
        pow = -pow;
        num = 1/num;
    }
    
    return num * RaiseNumberToPower(num, pow-1);
}

int SumOfSquaresAscending(int terms) {
    int total = 0;
    
    if (terms == 1) {
        cout << "1";
        return 1;
    } else {
        total = terms * terms + SumOfSquaresAscending(terms - 1);
        cout << " + (" + to_string(terms) + "*" + to_string(terms) + ")";
    }
    
    return total;
}

int SumOfSquaresDescending(int terms) {
    int total = 0;

    if (terms == 1) {
        cout << "1";
        return 1;
    } else {
        cout << "(" + to_string(terms) + "*" + to_string(terms) + ") + ";
        total = terms * terms + SumOfSquaresDescending(terms - 1);
    }

    return total;
}

void RunRaisePowerMenu() {
    double base;
    int power;
    bool exitMenu = false;
    
    do {
        cout << "Enter base number: (enter any letter to go back to the menu)\n";
        cin >> base;
        
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            exitMenu = true;
        } else {
            cout << "Enter power: ";
            cin >> power;
            
            cout << "Answer = " << RaiseNumberToPower(base, power);
            cout << "\n";
        }
    } while(exitMenu == false);
}

void RunAscendingMenu() {
    bool exitMenu = false;
    int numTerms;
    int total;
    
    do {
        cout << "Enter number of terms to add last\n(enter a letter to go back to the menu)\n";
        cin >> numTerms;
        
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            exitMenu = true;
        } else if (numTerms < 0) {
            cout << "Cannot accept negative numbers, please try again.\n";
            cin.clear();
            cin.ignore(100, '\n');
        } else {
            total = SumOfSquaresAscending(numTerms);
            cout << " = " << total;
            cout << "\n";
        }
    } while(exitMenu == false);
}

void RunDescendingMenu() {
    bool exitMenu = false;
    int numTerms;
    int total;
    
    do {
        cout << "Enter number of terms to add at first\n(enter a letter to go back to the menu)\n";
        cin >> numTerms;
        
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            exitMenu = true;
        } else if (numTerms < 0) {
            cout << "Cannot accept negative numbers, please try again.\n";
            cin.clear();
            cin.ignore(100, '\n');
        } else {
            total = SumOfSquaresDescending(numTerms);
            cout << " = " << total;
            cout << "\n";
        }
    } while(exitMenu == false);
}
