// LAB2 STAHL, DANIEL T TH

#include <iostream>
#include <string>

using namespace std;

int RaiseNumberToPower(int num, int pow);
string SumOfSquaresAscending(int terms, int& sum);
string SumOfSquaresDescending(int terms, int& sum);

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
                
                sumSquares = 0;
                cout << SumOfSquaresAscending(numTerms, sumSquares);
                
                cout << "\n";
                
                break;
            case 3:
                cout << "Enter number of terms to add at first" << endl;
                cin >> numTerms;
                cout << "\n";
                
                sumSquares = 0;
                cout << SumOfSquaresDescending(numTerms, sumSquares);
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

string SumOfSquaresAscending(int terms, int& sum) {
    string outputTerms;
    
    if (terms == 1) {
        sum += 1;
        outputTerms += "1";
    } else {
        sum += terms * terms;
        SumOfSquaresAscending(terms - 1, sum);
        outputTerms += " + (" + to_string(terms) + "*" + to_string(terms) + ")";
        
    }
    
    cout << outputTerms;
    return " = " + to_string(sum);
}

string SumOfSquaresDescending(int terms, int& sum) {
    static string outputTerms;

    if (terms == 1) {
        sum += 1;
        cout << "1";
    } else {
        sum += terms * terms;
        cout << "(" + to_string(terms) + "*" + to_string(terms) + ") + ";
        SumOfSquaresDescending(terms - 1, sum);
        

    }
    
    //cout << outputTerms;
    return " = " + to_string(sum);
}
