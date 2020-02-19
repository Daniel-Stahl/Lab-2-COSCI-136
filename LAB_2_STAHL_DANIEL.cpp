// LAB2 STAHL, DANIEL T TH

#include <iostream>
#include <string>

using namespace std;

int RaiseNumberToPower(int num, int pow);
void SumOfSquaresDescending(int terms, int &sum);

int main() {
    int base;
    int power;
    int userChoice;
    int numTerms;
    int sumSquares = 0;
    //string outputTerms;
    
    // Menu
    // 1. function that asks for base and power
    // 2.
    
    cout << "Choose from the menu below" << endl;
    
    while (userChoice != 4) {
        cout << "1. Raise the power of a number\n"
        << "2. Sum of squares\n"
        << "3. Sum of squares reverse\n"
        << "4. Quit program\n" << endl;
        
        cin >> userChoice;
        cout << "\n";
        
        switch (userChoice) {
            case 1:
                cout << "Enter base: ";
                cin >> base;
                cout << "Enter power: ";
                cin >> power;
                
                cout << RaiseNumberToPower(base, power);
                cout << "\n";
                
                break;
            case 2:
                cout << "Enter number of terms to add last" << endl;
                cin >> numTerms;
                cout << "\n";
                
//                for (int x = 0; x < numTerms; x++) {
//                    if (numTerms - x == 1) {
//                        outputTerms += "(" + to_string(numTerms - x) + ") ";
//                    } else {
//                        outputTerms += "(" + to_string(numTerms - x) + "*" + to_string(numTerms - x) + ") + ";
//                    }
//                }
//
//                cout << outputTerms << "= " << SumOfSquares(numTerms) << endl;
                
                SumOfSquaresDescending(numTerms, sumSquares);
                
                cout << "\n";
                
                break;
            case 3:
                cout << "Enter number of terms to add at first" << endl;
                cin >> numTerms;
                cout << "\n";
                
                break;
            default:
                break;
        }
    };
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

void SumOfSquaresDescending(int terms, int &sum) {
    string outputTerms;
    
    if (terms == 0 || terms < 0) {
        cout << "Cannot use that number, please try again\n" << endl;
    } else {
        sum += terms * terms;
        SumOfSquaresDescending(terms - 1, sum);
        
    }
    
    for (int x = 0; x < terms; x++) {
        if (terms - x == 1) {
            outputTerms += "(" + to_string(terms - x) + ") ";
        } else {
            outputTerms += "(" + to_string(terms - x) + "*" + to_string(terms - x) + ") + ";
        }
    }

    cout << outputTerms << "= " << sum << endl;
}


