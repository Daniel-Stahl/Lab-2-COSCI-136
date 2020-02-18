// LAB2 STAHL, DANIEL T TH

#include <iostream>
#include <string>

using namespace std;

int RaiseNumberToPower(int num, int pow);

int main() {
    int base;
    int power;
    int userChoice;
    
    
    // Menu
    // 1. function that asks for base and power
    // 2.
    
    cout << "Choose from the menu below" << endl;
    
    do {
        cout << "1. Raise the power of a number\n"
        << "2. Sum of squares\n"
        << "3. Sum of squares reverse\n" << endl;
        cin >> userChoice;
        cout << "\n";
        
        switch (userChoice) {
            case 1:
                cout << "Enter base: ";
                cin >> base;
                cout << "Enter power: ";
                cin >> power;
                
                cout << RaiseNumberToPower(base, power);
                break;
                
            default:
                break;
        }
    } while (userChoice > 0 && userChoice < 4);
    
    
    
    
    
}

int RaiseNumberToPower(int num, int pow) {
    if (pow == 0) {
        return 1;
    } else if (pow < 0) {
        return num * RaiseNumberToPower(num, pow + 1);
    } else {
        return num * RaiseNumberToPower(num, pow - 1);
    }
}


