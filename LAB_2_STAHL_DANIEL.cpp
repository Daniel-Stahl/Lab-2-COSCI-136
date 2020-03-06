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
        cout << "Main Menu\n" << "1. Raise the power of a number\n" << "2. Sum of squares ascending\n" << "3. Sum of squares descending\n" << "4. Quit program\n" << "Enter you selection: ";
        
        cin >> userChoice;
        //cout << "\n";
        
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
        cout << "\nEnter base number: (enter any letter to go back to the menu)\n";
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
        cout << "\nEnter number of terms to add last\n(enter a letter to go back to the menu)\n";
        cin >> numTerms;
        
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            exitMenu = true;
        } else if (numTerms < 0) {
            cout << "\nCannot accept negative numbers, please try again.\n";
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
        cout << "\nEnter number of terms to add at first\n(enter a letter to go back to the menu)\n";
        cin >> numTerms;
        
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            exitMenu = true;
        } else if (numTerms < 0) {
            cout << "\nCannot accept negative numbers, please try again.\n";
            cin.clear();
            cin.ignore(100, '\n');
        } else {
            total = SumOfSquaresDescending(numTerms);
            cout << " = " << total;
            cout << "\n";
        }
    } while(exitMenu == false);
}

/*

 Main Menu
 1. Raise the power of a number
 2. Sum of squares ascending
 3. Sum of squares descending
 4. Quit program
 Enter you selection: 1
 
 Enter base number: (enter any letter to go back to the menu)
 3
 Enter power: 4
 Answer = 81
 
 Enter base number: (enter any letter to go back to the menu)
 -5
 Enter power: 3
 Answer = -125
 
 Enter base number: (enter any letter to go back to the menu)
 -3
 Enter power: -4
 Answer = 0.0123457
 
 Enter base number: (enter any letter to go back to the menu)
 3
 Enter power: -6
 Answer = 0.00137174
 
 Enter base number: (enter any letter to go back to the menu)
 7
 Enter power: 0
 Answer = 1
 
 Enter base number: (enter any letter to go back to the menu)
 0
 Enter power: -4
 
 Answer = Undefined, can't divide by 0
 
 Main Menu
 1. Raise the power of a number
 2. Sum of squares ascending
 3. Sum of squares descending
 4. Quit program
 Enter you selection: 2
 
 Enter number of terms to add last
 (enter a letter to go back to the menu)
 4
 1 + (2*2) + (3*3) + (4*4) = 30
 
 Enter number of terms to add last
 (enter a letter to go back to the menu)
 8
 1 + (2*2) + (3*3) + (4*4) + (5*5) + (6*6) + (7*7) + (8*8) = 204
 
 Enter number of terms to add last
 (enter a letter to go back to the menu)
 3
 1 + (2*2) + (3*3) = 14
 
 Enter number of terms to add last
 (enter a letter to go back to the menu)
 r
 Main Menu
 1. Raise the power of a number
 2. Sum of squares ascending
 3. Sum of squares descending
 4. Quit program
 Enter you selection: 3
 
 Enter number of terms to add at first
 (enter a letter to go back to the menu)
 5
 (5*5) + (4*4) + (3*3) + (2*2) + 1 = 55
 
 Enter number of terms to add at first
 (enter a letter to go back to the menu)
 3
 (3*3) + (2*2) + 1 = 14
 
 Enter number of terms to add at first
 (enter a letter to go back to the menu)
 7
 (7*7) + (6*6) + (5*5) + (4*4) + (3*3) + (2*2) + 1 = 140
 
 Enter number of terms to add at first
 (enter a letter to go back to the menu)
 r
 Main Menu
 1. Raise the power of a number
 2. Sum of squares ascending
 3. Sum of squares descending
 4. Quit program
 Enter you selection: 2
 
 Enter number of terms to add last
 (enter a letter to go back to the menu)
 -4
 
 Cannot accept negative numbers, please try again.
 
 Enter number of terms to add last
 (enter a letter to go back to the menu)
 r
 Main Menu
 1. Raise the power of a number
 2. Sum of squares ascending
 3. Sum of squares descending
 4. Quit program
 Enter you selection: 3
 
 Enter number of terms to add at first
 (enter a letter to go back to the menu)
 -7
 
 Cannot accept negative numbers, please try again.
 
 Enter number of terms to add at first
 (enter a letter to go back to the menu)
 r
 Main Menu
 1. Raise the power of a number
 2. Sum of squares ascending
 3. Sum of squares descending
 4. Quit program
 Enter you selection: 4
 Program ended with exit code: 0
 
*/
