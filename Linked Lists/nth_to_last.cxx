//
//  Cracking the Coding Interview Q2.2
//  Return the kth to last element of a singly linked list
//  Assume that the length is NOT given (this would be too easy!)
//
//  Joel Rorseth
//  Created on May 15, 2017
//

#include <iostream>
#include <set>


// MARK: Simple Linked List Implementation (Given)
// Linked List Node
template <typename T>
struct Node {

    Node<T> * next = nullptr;
    T value;
};

// Insert into Linked List (back), Assumes head is non-null
template <typename T>
void insert_back(Node<T> * head, T value) {

    Node<T> * new_ptr = new Node<T>;
    new_ptr->next = nullptr;
    new_ptr->value = value;

    Node<T> * temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new_ptr;
}

// Print Linked List
template <typename T>
void print_list(Node<T> * head) {

    while (head) {
        std::cout << head->value << " -> ";
        head = head->next;
    }

    std::cout << "NULL" << std::endl;
}


// Solution
template <typename T>
Node<T> * nth_to_last(Node<T> * head, T k) {

    // Use the runner approach and start a second 'fast' pointer k nodes ahead
    // The differnece between 'fast' and 'slow' will always be k if both incremented
    
    Node<T> * fast = head;
    Node<T> * slow = head;

    for (int i = 0; i < k; ++i) {
        if (!fast)
            return nullptr;    // Null indicates size < k

        fast = fast->next;
    }

    // Advance the fast pointer until end of list
    // The slow runner will be the kth to last

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}


// Demonstration
int main(int argc, char * argv[]) {

    // Note: Creating Node pointer with dynamic memory allocation will
    // automatically construct it, making it a proper Node with value 0

    Node<int> * head = new Node<int>;

    // Generate Linked List
    for (int i = 1; i < 7; i++) 
        insert_back(head, i);

    std::cout << "Linked List...\n\t";
    print_list(head);

    // Output
    std::cout << "\nThe 4th last element is " 
        << nth_to_last(head, 4)->value << std::endl;
}

