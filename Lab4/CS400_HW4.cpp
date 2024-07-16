// CS400_HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// question 1
bool isBalanced(const string& str) {
    stack<char> p;

    // if the character is an opening parenthesis, push it onto the stack
    for (char ch : str) {
        if (ch == '(' || ch == '<') {
            p.push(ch);
        }
        // if the character is a closing parenthesis, check for balance
        else if (ch == ')' || ch == '>') {
            if (p.empty()) {
                // If stack is empty and encountering a closing parenthesis, it's unbalanced
                return false;
            }
            char top = p.top();
            p.pop();
            // check if the top of the stack matches the current closing parenthesis
            if ((ch == ')' && top != '(') || (ch == '>' && top != '<')) {
                return false;
            }
        }
    }

    // if the stack is empty at the end, all parenteses were balanced
    return p.empty();
}

// question 2
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value) :data{ value }, prev{ nullptr }, next{ nullptr } {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

    ~DoublyLinkedList() {
        while (!isEmpty()) {
            removeFront();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void addFront(int item) {
        Node* newNode = new Node(item);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addBack(int item) {
        Node* newNode = new Node(item);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void removeFront() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }

        Node* del = head;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete del;
        size--;
    }

    void removeBack() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }

        Node* del = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete del;
        size--;
    }

    void printForward() const {
        Node* current = head;

        if (isEmpty()) {
            cout << "List is empty" << endl;
        }
        else {
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << " null " << endl;
        }
    }

    void printBackward() const {
        Node* current = tail;

        if (isEmpty()) {
            cout << "List is empty" << endl;
        }
        else {
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->prev;
            }
            cout << " null " << endl;
        }
    }
};

// Convert to template
template<typename T>
class DoublyLinkedList_Tem {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T value) :data{ value }, prev{ nullptr }, next{ nullptr } {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList_Tem() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

    ~DoublyLinkedList_Tem() {
        while (!isEmpty()) {
            removeFront();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void addFront(const T& item) {
        Node* newNode = new Node(item);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addBack(const T& item) {
        Node* newNode = new Node(item);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void removeFront() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }

        Node* del = head;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete del;
        size--;
    }

    void removeBack() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }

        Node* del = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete del;
        size--;
    }

    void printForward() const {
        Node* current = head;

        if (isEmpty()) {
            cout << "List is empty" << endl;
        }
        else {
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << " null " << endl;
        }
    }

    void printBackward() const {
        Node* current = tail;

        if (isEmpty()) {
            cout << "List is empty" << endl;
        }
        else {
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->prev;
            }
            cout << " null " << endl;
        }
    }
};

int main()
{
    // question 1 testing
    string test1 = "<>()<()>(<>)";
    string test2 = "(<)>";
    string test3 = "><><";
    string test4 = "())";
    string test5 = "<<>";
    string test6 = "<><<>>()(())";

    cout << test1 << " is " << (isBalanced(test1) ? "balanced" : "not balanced") << endl;
    cout << test2 << " is " << (isBalanced(test2) ? "balanced" : "not balanced") << endl;
    cout << test3 << " is " << (isBalanced(test3) ? "balanced" : "not balanced") << endl;
    cout << test4 << " is " << (isBalanced(test4) ? "balanced" : "not balanced") << endl;
    cout << test5 << " is " << (isBalanced(test5) ? "balanced" : "not balanced") << endl;
    cout << test6 << " is " << (isBalanced(test6) ? "balanced" : "not balanced") << endl;

    // question 2 testing
    DoublyLinkedList dll;
    dll.addFront(1);
    dll.addFront(2);
    dll.addFront(3);
    dll.addBack(4);
    dll.printForward(); // 3->2->1->4->null
    dll.printBackward(); // 4->1->2->3->null

    // convert to template
    DoublyLinkedList_Tem<string> dll_str;
    dll_str.addFront("1");
    dll_str.addFront("2");
    dll_str.addFront("3");
    dll_str.addBack("4");
    dll_str.printForward(); // 3->2->1->4->null
    dll_str.printBackward(); // 4->1->2->3->null
}

