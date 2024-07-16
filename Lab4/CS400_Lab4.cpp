// CS400_Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

void decimalToHexadecimal(int decimalNumber) {
    // create empty stack of characters
    stack<char> hexStack;

    // Special case for 0
    // TODO:
    // if the number entered is a 0 it outputs the statement and returns from the function
    if (decimalNumber == 0) {
        cout << "Hexadecimal representation: 0" << endl;
        return;
    }

    // Convert decimal to hexadecimal using stack
    // TODO:
    // while the number is greater than 0, the remainder is found when the decimal is divided by 16
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        char hexDigit;

        // if remainder is less than 10, it corresponds to the characters 0 to 9
        // if it's more than 10, it corresponds to the characters a to f
        if (remainder < 10) {
            hexDigit = remainder + '0';
        }
        else {
            hexDigit = remainder - 10 + 'A';
        }

        // then push the corresponding character onto the stack
        hexStack.push(hexDigit);
        // then divide the decimal number by 16 and continue the loop until the decimal number becomes 0
        decimalNumber /= 16;
    }

    // Print the hexadecimal representation
    cout << "Hexadecimal representation: ";
    // TODO:
    // pops each character from the stack and prints it. This gives the hexadecimal representation in the correct
    // order since the stack reverses the order of insertion
    while (!hexStack.empty()) {
        cout << hexStack.top();
        hexStack.pop();
    }
    cout << endl;
}

// Use the code from main() to test your result:
int main()
{
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    decimalToHexadecimal(decimalNumber);

    return 0;
}
