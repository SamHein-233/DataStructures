// CS400_Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // constructor:
    // TOdo: implement constructor:
    // initializes the head tail and size
    CircularLinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

    // destructor:
    // clears the list by repeatedly removing the front element until the list is empty
    ~CircularLinkedList() {
        // TODO: 
        while (!isEmpty()) {
            removeFront();
        }
    }

    // checks if the list is empty
    bool isEmpty() const {
        // TODO:
        return size == 0;
    }

    // gets the size of the list
    int getSize() const {
        // TODO:
        return size;
    }

    // adds an item to the front of the list
    void addFront(const T& item) {
        // TODO:
        // new node is created with the data from item
        Node* newNode = new Node(item);
        // checks if the list is empty, if it is the new node's next pointer points to itself (newNode)
        // and the tail is updated to the newNode
        if (isEmpty()) {
            newNode->next = newNode;
            tail = newNode;
        }
        // if the list is not empty then the new node's pointer is set to the current head
        // then the tail pointer is updated to point to the new node
        else {
            newNode->next = head;
            tail->next = newNode;
        }
        // and finally the head is updated
        head = newNode;
        size++;
    }

    // adds an item to the back of the list
    void addBack(const T& item) {
        // TODO:
        Node* newNode = new Node(item);
        if (isEmpty()) {
            newNode->next = newNode;
            head = newNode;
        }
        // if the list is not empty, the new node's next pointer is set to head
        // the current tail's next pointer is updated to the new node
        else {
            newNode->next = head;
            tail->next = newNode;
        }
        // and finally the tail is updated to the new node
        tail = newNode;
        size++;
    }

    // removes an item from the front of the list
    void removeFront() {
        // TODO:
        // checks if the list is empty
        if (isEmpty()) {
            return;
        }
        // store the node to be deleted
        Node* temp = head;
        // check if there's only one node
        // if there is only one node, both head and tail are set to mullptr, making the list empty
        if (head == tail) {
            head = tail = nullptr;
        }
        // if there are multiple nodes, the head is updated to the next node. the tail pointer is updated to the new head
        else {
            head = head->next;
            tail->next = head;
        }
        delete temp;
        size--;
    }

    // removes an item from the back of the list
    void removeBack() {
        // TODO:
        if (isEmpty()) {
            return;
        }
        // store the node to be deleted
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        // if there are multiple nodes a pointer is used to traverse the list to find the node before the tail
        // the current pointer is set to head and tail is updated
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = head;
            tail = current;
        }
        delete temp;
        size--;
    }

    void print() const {
        // TODO:
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        // initialize a pointer to traverse the list
        Node* current = head;
        // the function enters a do while loop to traverse the list and print
        // the data of each node, loop continues until current points to head
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

// implement quque class using composition of circular linked list:
template <typename T>
class Queue {
private:
    CircularLinkedList<T> list;

public:
    // TODO:
    bool isEmpty() const {
        return list.isEmpty();
    }

    int getSize() const {
        return list.getSize();
    }

    void enqueue(const T& item) {
        list.addBack(item);
    }

    void dequeue() {
        list.removeFront();
    }

    T front() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return list.getFront();
    }

    void print() const {
        list.print();
    }
};

int main()
{
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.print();  // Output: 1 -> 2 -> 3

    queue.dequeue();
    queue.print();  // Output: 2 -> 3
}

