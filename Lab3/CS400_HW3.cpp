// CS400_HW3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// this defines a structure that represent an element in the linked list
struct Node {
    //TODO:
    // 
    // an integer to store the data of the node
    int data;
    // a pointer to the next node in the linked list
    Node* next;
};

// a type definition for a pointer to a Node. It simplifies the usage of pointer to nodes in the code
typedef Node* NodePtr;

// Function to create a new node with the given data
NodePtr createNode(int data) {
    //TODO:

    // allocates memory for a new node
    NodePtr newNode = new Node;
    // assigns data to the node
    newNode->data = data;
    // initializes the next pointer sing it's a standalone node at this point
    newNode->next = nullptr;
    return newNode;
}

// Function to print the linked list
void printList(NodePtr head) {
    //TODO:

    // initializes a pointer to traverse the list
    NodePtr cur = head;
    // lopps through the list until it reaches the end
    while (cur != nullptr) {
        // prints out current data
        cout << cur->data << " ";
        // moves to the next node
        cur = cur->next;
    }
    cout << endl;
}




NodePtr mergeSortedLists(NodePtr list1, NodePtr list2) {
    //TODO:
    // if first list is empty, return second list and vice versa
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    // determine head of the merged list
    NodePtr mergedHead = nullptr;
    // if the first element of list 1 is smllaer set mergedHead to list1 and move to the next element in list 1
    if (list1->data < list2->data) {
        mergedHead = list1;
        list1 = list1->next;
    }
    else {
        mergedHead = list2;
        list2 = list2->next;
    }

    // initializes  a pointer to cur to track the current positoin in the merged list
    NodePtr cur = mergedHead;

    // loops through both lists until one is exhausted
    while (list1 != nullptr && list2 != nullptr) {
        // compare the current element of list 1 and list 2
        // append the smaller element to the merged list and move the pointer to the corresponding list
        if (list1->data < list2->data) {
            cur->next = list1;
            list1 = list1->next;
        }
        else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }

    // Append the remaining element from the non-exhausted list
    if (list1 != nullptr) {
        cur->next = list1;
    }
    else {
        cur->next = list2;
    }
    return mergedHead;
}

void rearrangeLinkedList(NodePtr& head) {
    //TODO:
    if (head == nullptr) return;

    // initialize four pointers to manage odd and even lists
    NodePtr oddHead = nullptr, oddTail = nullptr;
    NodePtr evenHead = nullptr, evenTail = nullptr;
    NodePtr cur = head;

    // traverse the original list
    while (cur != nullptr) {
        // for each node check if its data is even or odd
        // append the node to the appropriate list
        // update the tail pointers accordingly
        if (cur->data % 2 == 0) {
            if (evenHead == nullptr) {
                evenHead = evenTail = cur;
            }
            else {
                evenTail->next = cur;
                evenTail = evenTail->next;
            }
        } else {
            if (oddHead == nullptr) {
                oddHead = oddTail = cur;
            }
            else {
                oddTail->next = cur;
                oddTail = oddTail->next;
            }
        }
        cur = cur->next;
    }

    // if there are odd elements, link the tail of the odd list to the head of the even list
    if (oddTail != nullptr) {
        oddTail->next = evenHead;
    }
    // ensure the last node of the even list points to terminate the combined list
    if (evenTail != nullptr) {
        evenTail->next = nullptr;
    }

    // Update the head pointer to point to the new head of the rearranged list
    head = (oddHead != nullptr) ? oddHead : evenHead;
}



// test your solution:
int main() {
    // Create the first linked list: 1->3->5->7
    NodePtr list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
    list1->next->next->next = createNode(7);

    // Create the second linked list: 2->4->6->8
    NodePtr list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    list2->next->next->next = createNode(8);

    // Merge the two sorted lists
    NodePtr mergedList = mergeSortedLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    // Clean up the memory
    NodePtr current = mergedList;
    while (current != nullptr) {
        NodePtr temp = current;
        current = current->next;
        delete temp;
    }

    // Create the linked list: 1 -> 2 -> 5 -> 8 -> 3 -> 6 -> 7 -> 4
    NodePtr head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(5);
    head->next->next->next = createNode(8);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(4);

    // Print the original list
    std::cout << "Original List: ";
    printList(head);

    // Re-arrange the list
    rearrangeLinkedList(head);

    // Print the re-arranged list
    std::cout << "Re-arranged List: ";
    printList(head);

    // Clean up the memory
    while (current != nullptr) {
        NodePtr temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
