//
//  Cracking the Coding Interview Q2.3
//  Delete a given node from a singly linked list.
//
//  Joel Rorseth
//  Created on May 18, 2017
//

#include <iostream>

// Note: It is not possible to delete the last node of a singly
// linked list using this method. There really is no other way 
// without having the deleted node's previous value (eg. doubly
// linked list).


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
bool delete_node(Node<T> * node) {

    // Existing list cannot be size 1 or 0
    if (node == nullptr || node->next == nullptr)
        return false;

    // Cannot access previous node due to it being singly linked,
    // instead replace deleted node with deleted node's next node
    
    Node<T> * next = node->next;
    node->value = next->value;
    node->next = next->next;

    // In C++, we must delete dynamically allocated memory manually!
    delete next;
    return true;
}


// Demonstration
int main() {

    Node<int> * head = new Node<int>;
    Node<int> * second = new Node<int>;

    head->next = second;
    second->value = 7;

   for (int i = 1; i < 4; i++) 
        insert_back(head, i);

   std::cout << "Linked List: ";
   print_list(head);

   delete_node<int>(second);
   std::cout << "\nAfter removing second node...\nLinked List: ";
   print_list(head);

}
