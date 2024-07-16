// CS400_Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // TODO: implement the following function:
    // this performs an in-order traversal to collect the tree node values in a vetor
    // then checks if the vector is sorted in increading order
    bool isValidBST(TreeNode* root) {
        // create an empty vector to store the values of the nodes
        vector<int> elements;
        // calls the inorderTraversal function to fill the vector with the values from the binary tree
        inorderTraversal(root, elements);
        for (size_t i = 1; i < elements.size(); ++i) {
            // checks if the current element is less than or equal to the previous element
            if (elements[i] <= elements[i - 1]) {
                return false;
            }
        }
        return true;
    }

private:
    // TODO: implement the following funtion:
    // this performs an in-order traversal of binary tree and stores the code values in the vector elements
    void inorderTraversal(TreeNode* root, std::vector<int>& elements) {
        if (root == nullptr) {
            return;
        }
        // recursively calls itself on the left child of the current node
        inorderTraversal(root->left, elements);
        // adds the value of the current node to the elements vector
        elements.push_back(root->val);
        // recursively calls itself on the right child of the current node
        inorderTraversal(root->right, elements);
    }
};

// TODO: implement the following function:
TreeNode* findMinNode(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    // initializes a pointer to start at the root of the tree
    TreeNode* current = root;
    // enters a loop as long as the current node has a left child
    while (current->left != nullptr) {
        // moves the pointer to the left child of the current node
        // this traversal continues until it points to the leftmost node
        current = current->left;
    }
    return current;
}

// TODO: implement the following function:
TreeNode* findMaxNode(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}




// Use the code from main to test your solution:
// the output should be: 
// The binary tree is a valid binary search tree.
// min node: 2
// max node: 8

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);



    Solution solution;
    if (solution.isValidBST(root)) {
        cout << "The binary tree is a valid binary search tree." << std::endl;
    }
    else {
        cout << "The binary tree is NOT a valid binary search tree." << std::endl;
    }


    TreeNode* minNode = findMinNode(root);
    cout << "min node: " << minNode->val << std::endl;


    TreeNode* maxNode = findMaxNode(root);
    cout << "max node: " << maxNode->val << std::endl;

    // Don't forget to free the allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

}

