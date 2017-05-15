//
//  Cracking the Coding Interview Q2.1
//  Delete duplicates from a linked list
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
void delete_duplicates(Node<T> * list) {

    // Keep a a set of all values seen at any point
    // If value has been seen, unlink it

    std::set<T> seen{};
    Node<T> * previous = nullptr;

    while (list != nullptr) {

        // If found, previous->next becomes  duplicate->next
        if (seen.find(list->value) != seen.end())
            previous->next = list->next;
        else {
            seen.insert(list->value);
            previous = list;
        }

        list = list->next;
    }
}


// Demonstration
int main(int argc, char * argv[]) {

    // Note: Creating Node pointer with dynamic memory allocation will
    // automatically construct it, making it a proper Node with value 0

    Node<int> * head = new Node<int>;
    
    // Generate Linked List with duplicates
    for (int i = 1; i < 7; i++) 
        insert_back(head, i % 4);

    std::cout << "Linked List with duplicates...\n\t";
    print_list(head);

    // Delete duplicates and display
    std::cout << "Linked List after removing duplicates...\n\t";
    delete_duplicates(head);
    print_list(head);
}
