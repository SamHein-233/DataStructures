// CS400_HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

// question 1
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string postfixToInfix(const string& postfix) {
    stack<string> s;

    for (char ch : postfix) {
        if (isOperator(ch)) {
            // pop the top two elements from the stack
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            // form a new string with the operator in between
            string expr = "(" + op1 + " " + ch + " " + op2 + ")";

            // push the resulting string back onto the stack
            s.push(expr);
        }
        else {
            // if the character is an operand, push it onto the stack
            s.push(string(1, ch));
        }
    }
    // the final result should be the only element left in the stack
    return s.top();
}

// question 2
void deleteThirdElement(queue<int>& q) {
    // TODO: implement this function:
    if (q.size() < 3) {
        cerr << "Queue doesn't have enough elements." << endl;
        return;
    }
    queue<int> tempQueue;

    // move the first two elements to the temporary queue
    for (int i = 0; i < 2; ++i) {
        tempQueue.push(q.front());
        q.pop();
    }

    // remove the third element
    q.pop();

    // move the rest of the elements to the temporary queue
    while (!q.empty()) {
        tempQueue.push(q.front());
        q.pop();
    }

    // move elements back to the original queue
    q = tempQueue;
}

// question 3
void deleteMiddleElement(std::queue<int>& q, int position) {
    // TODO: implement this function:
    if (position < 0 || position >= q.size()) {
        cerr << "Position is out of range" << endl;
        return;
    }
    queue<int> tempQueue;
    int size = q.size();

    // move elements before the position to the temporary queue
    for (int i = 0; i < size; ++i) {
        if (i != position) {
            tempQueue.push(q.front());
        }
        q.pop();
    }

    // move elements back to the original queue
    q = tempQueue;
}

int main()
{
    // question 1

    string postfix1 = "ABC*+D+";
    string infix1 = postfixToInfix(postfix1);
    cout << "Postfix: " << postfix1 << "\nInfix: " << infix1 << endl;

    string postfix2 = "AB+CDE/*-F+";
    string infix2 = postfixToInfix(postfix2);
    cout << "Postfix: " << postfix2 << "\nInfix: " << infix2 << endl;

    // question 2
    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);

    cout << "Original Queue: ";
    queue<int> tempQueue = myQueue;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    deleteThirdElement(myQueue);

    cout << "Modified Queue: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    // question 3
    queue<int> myQueue2;
    myQueue2.push(1);
    myQueue2.push(2);
    myQueue2.push(3);
    myQueue2.push(4);
    myQueue2.push(5);

    std::cout << "Original Queue: ";
    queue<int> tempQueue2 = myQueue2;
    while (!tempQueue2.empty()) {
        std::cout << tempQueue2.front() << " ";
        tempQueue2.pop();
    }
    std::cout << std::endl;

    // Delete the element at position 2 (0-based index)
    deleteMiddleElement(myQueue2, 2);

    std::cout << "Modified Queue: ";
    while (!myQueue2.empty()) {
        std::cout << myQueue2.front() << " ";
        myQueue2.pop();
    }
    std::cout << std::endl;
}
