// CS400_Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MyVector {
private:
    int* data;
    size_t size;
    size_t capacity;

public:
    MyVector() : data{ nullptr }, size{ 0 }, capacity{ 0 } {}

    MyVector(size_t initialCapacity) : data{ nullptr }, capacity{ initialCapacity } {
        data = new int[capacity];
    }

    ~MyVector() {
        delete[] data;
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return (size == 0);
    }

    int& operator[] (size_t index) {
        if (index >= size) {
            throw out_of_range("Index is out of range");
        }
        return data[index];
    }

    void pushBack(int value) {
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            int* newData = new int[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size] = value;
        size++;
    }

    void popBack() {
        if (size == 0) {
            throw out_of_range("Vector is empty");
        }
        --size;
    }

    void insert(size_t index, int value) {
        if (index > size) {
            throw out_of_range("Index is out of range");
        }
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            int* newData = new int[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    void erase(size_t index) {
        if (index >= size) {
            throw out_of_range("Index is out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }
};

// TODO: implement template class: vector here

template <typename T>
class Vector {
private:
    // pointer to dynamic array holding the vector elements
    T* data;
    // current number of elements in the vector
    size_t size;
    // current capacity of the allocated memory
    size_t capacity;

public:
    Vector() : data(nullptr), size(0), capacity(0) {}

    Vector(size_t initialSize) : size(initialSize), capacity(initialSize) {
        data = new T[initialSize];
    }

    ~Vector() {
        delete[] data;
    }

    // returns the number of elements
    size_t getSize() const {
        return size;
    }
    
    // checks if the vector is empty
    bool isEmpty() const {
        return size == 0;
    }

    // provides access to elements with bounds checking
    T& operator[] (size_t index) {
        if (index >= size) {
            throw out_of_range("Index is out of range");
        }
        return data[index];
    }

    // adds an element to the end. Resizes if necessary
    void pushBack(const T& value) {
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size] = value;
        ++size;
    }

    // Removes the last element with a bounds check
    void popBack() {
        if (size == 0) {
            throw out_of_range("Vector is empty");
        }
        --size;
    }

    // Inserts an element at a specified index. Moves elements if necessary and resizes if needed
    void insert(size_t index, const T& value) {
        if (index > size) {
            throw out_of_range("Index is out of range");
        }
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : 2 * capacity;
            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    // Removes the element at a specified index and shifts remaining elements
    void erase(size_t index) {
        if (index >= size) {
            throw out_of_range("Index is out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }
};


// use the code from main() to test your solution:

int main()
{
    Vector<int> vec;
    vec.pushBack(10);
    vec.pushBack(20);
    vec.pushBack(30);
    vec.insert(1, 100);
    vec.insert(2, 200);
    cout << vec.getSize() << endl;
    vec.erase(vec.getSize() - 1);
    vec.popBack();



    cout << "Size of vector: " << vec.getSize() << endl;
    cout << "Vector elements: ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    Vector<string> s_vec;
    s_vec.pushBack("a");
    s_vec.pushBack("b");
    s_vec.pushBack("c");


    cout << "Size of vector: " << s_vec.getSize() << endl;
    cout << "Vector elements: ";
    for (size_t i = 0; i < s_vec.getSize(); ++i) {
        cout << s_vec[i] << " ";
    }
    cout << endl;
}
