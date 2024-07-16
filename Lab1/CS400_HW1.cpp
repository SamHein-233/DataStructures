// CS400_HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number) { 
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void printFormulaOne() {
    cout << "40 primes genereated by n^2 + n + 41:" << " ";
    for (int n = 0; n <= 39; ++n) {
        int value = n * n + n + 41;
        if (isPrime(value)) {
            cout << value << " ";
        }
    }
    cout << endl;
}

void printFormulaTwo() {
    cout << "80 primes genereated by n^2 - 79n + 1601:" << " ";
    for (int n = 0; n <= 79; ++n) {
        int value = n * n - 79 * n + 1601;
        if (isPrime(value)) {
            cout << value << " ";
        }
    }
    cout << endl;
}

void findMaxPrimes() {
    int maxPrimes = 0;
    int bestA = 0, bestB = 0;

    for (int a = -999; a <= 999; ++a) {
        for (int b = -1000; b <= 1000; ++b) {
            int n = 0;
            while (isPrime(n * n + a * n + b)) {
                ++n;
            }
            if (n > maxPrimes) {
                maxPrimes = n;
                bestA = a;
                bestB = b;
            }
        }
    }

    cout << "The best values are a = " << bestA << ", b = " << bestB << " with " << maxPrimes << " consecutive primes." << endl;
}

int main()
{
    printFormulaOne();
    printFormulaTwo();
    findMaxPrimes();
    
}

