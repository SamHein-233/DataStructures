// CS400_Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;


// TODO: include the header file for std::stringstream



// Prints frequencies of 
// individual words in str

void printFrequencies(const string& str)
{
    // TODO:
    // declaring map of <string, int> type, each word is mapped to its frequency

    // this map is declared to store the frequency of each word, string being the word, and int being the frequency
    unordered_map<string, int> wordFreq;

    // TODO:
    // breaking input into word using string stream Used for breaking words

    // stringsteam object is created and initialized with input string, this allows the string to be processed word by word
    stringstream ss(str);

    // TODO:
    // To store individual words

    // the word variable is declared to store each word as it is extracted
    string word;
    // this loop uses the >> operator to extract words from the stringstream one by one
    // each word extracted the count of that word is incremented in the map
    while (ss >> word) {
        wordFreq[word]++;
    }

    // TODO:
    // now iterating over word, freq pair and printing them in <, > format

    // this loop iterates over each key value (string from declared map)
    // const auto& pair ensures that each pair is a constant reference to an element in
    // the map so that unecessary copies are avoided
    // Then in the loop the word and then the frequency is output
    for (const auto& pair : wordFreq) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }
}

// Test code
int main()
{
    string str = "do not let trouble trouble you do";
    printFrequencies(str);
}

// your output: 
// (you, 1)
// (do, 2)
// (let, 1)
// (not, 1)
// (trouble, 2)

