// CS400_HW6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// definnition of Node struct
template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    Node(T value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


// definition of BinarySearchTree class
template <typename T>
class BinarySearchTree {
private:
    Node<T>* root;
    int count;

    void destroy(Node<T>* ptr) { // helper
        if (ptr == nullptr) {
            return;
        }

        destroy(ptr->left);
        destroy(ptr->right);
        delete ptr;
    }

    void insert(T value, Node<T>*& ptr) { // helper
        if (!ptr) {
            ptr = new Node<T>(value);
            return;
        }
        else if (value < ptr->data) {
            insert(value, ptr->left);
        }
        else {
            insert(value, ptr->right);
        }
    }

    Node<T>* makeNode(T value) {
        return new Node<T>(value);
    }

    void inorder(Node<T>* ptr) const { // helper
        if (ptr != nullptr) {
            inorder(ptr->left);
            cout << ptr->data << " ";
            inorder(ptr->right);
        }
    }

    void preorder(Node<T>* ptr) const { // helper
        if (ptr == nullptr) {
            return;
        }
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void postorder(Node<T>* ptr) const { // helper
        if (ptr == nullptr) {
            return;
        }
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
        
    }

public:
    // constructor:
    BinarySearchTree() {
        root = nullptr;
        count = 0;
    }
    ~BinarySearchTree() { // destructor
        destroy(root);
    }

    void insert(T value) {
        insert(value, root);
        count++;
    }

    void inorder() const {
        inorder(root);
        cout << endl;
    }

    void preorder() const {
        preorder(root);
        cout << endl;
    }

    void postorder() const {
        postorder(root);
        cout << endl;
    }

    int size() const {
        return count;
    }

    bool empty() const {
        return root == nullptr;
    }

};

int main()
{
    // test 1:
    BinarySearchTree<int> bct;
    bct.insert(1);
    bct.insert(20);
    bct.insert(3);
    bct.insert(7);
    bct.insert(13);
    bct.insert(5);


    std::cout << "inorder: " << std::endl;
    bct.inorder();

    std::cout << "preorder: " << std::endl;
    bct.preorder();

    std::cout << "postorder: " << std::endl;
    bct.postorder();


    std::cout << "size: " << bct.size() << std::endl;



    // test 2:

    // Instantiation of a binary search tree object
    BinarySearchTree <string> bst;
    // Inserting six nodes in the tree
    bst.insert("Michael");
    bst.insert("Jane");
    bst.insert("Sophie");
    bst.insert("Thomas");
    bst.insert("Rose");
    bst.insert("Richard");
    // Printing values using preorder traversal
    std::cout << "Using preorder traversal" << std::endl;
    bst.preorder();
    std::cout << std::endl << std::endl;
    // Printing values using inorder traversal 
    std::cout << "Using inorder traversal" << std::endl;
    bst.inorder();
    std::cout << std::endl << std::endl;
    // Printing values using postorder traversal 
    std::cout << "Using postorder traversal" << std::endl;
    bst.postorder();
    std::cout << std::endl << std::endl;

}
