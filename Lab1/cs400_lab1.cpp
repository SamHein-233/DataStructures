// TODO: include proper headers here
#include <iostream>
#include <string>
// what header is needed for square root function ?? 
#include <cmath>
using namespace std;

// TODO: complete prime tester function 
// TA: please explain this part to the class. Then ask students to complete main function
// to generate desired output.
bool isPrime(int number) {
    // TODO: complete the condition here 
    // guard negative numbers, 0 and 1, as they are not considered as prime numbers.  
    if (number <= 1) {
        return false;
    }

    // TODO: complete the for loop to test all possible factors
    // possible factors starts from 2 (inclusive) and goes all the way to sqrt(n) + 1 (inclusive) 
    for (int i = 2; i <= sqrt(number); ++i) {
        // checks if number is divisible by i. Modulous operator rerturns remainder
        // if number is divisible by any i within the range then the number cannot be prime
        if (number % i == 0) {
            return false;
        }
    }

    // no factor found, return true
    return true;
}

// question 2: to be completed by students. 
// TA may give general guidelines but will not help on code level. 
// develop a function to return the 10001st prime number. 
// correct answer: 104743
int the10001PrimeNumber() {
    // count keeps track of how many prime numbers have been found so far.
    int count = 0;
    int number = 1;

    while (count < 10001) {
        ++number;
        if (isPrime(number)) {
            ++count;
        }
    }
    return number;
}



// TODO: please finish the main function.  
int main() {
    // question 1's main() function requirement: 
    // generate following output by using isPrime() function: 
    /*
    1 is NOT a prime number.
    2 is a prime number.
    3 is a prime number.
    4 is NOT a prime number.
    5 is a prime number.
    6 is NOT a prime number.
    7 is a prime number.
    8 is NOT a prime number.
    9 is NOT a prime number.
    10 is NOT a prime number.
    11 is a prime number.
    12 is NOT a prime number.
    13 is a prime number.
    14 is NOT a prime number.
    15 is NOT a prime number.
    16 is NOT a prime number.
    17 is a prime number.
    18 is NOT a prime number.
    19 is a prime number.
    */

    for (int i = 1; i <= 19; ++i) {
        if (isPrime(i)) {
            cout << i << " is a prime number" << endl;
        }
        else
        {
            cout << i << " is NOT a prime number" << endl;
        }
    }

    // question 2's code. 
    // Please complete the function the10001PrimeNumber() first, 
    // then uncomment following code to generate desired output
    cout << "The 10001st prime number: " << the10001PrimeNumber() << endl;


}