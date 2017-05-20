//
//  Cracking the Coding Interview Q2.4
//  Partition a linked list such that all elements with value < x
//  (given) appear before all elements >= x. If x is contained within
//  the list, x only has to appear in the 'right' partition, and does
//  not have to appear 'in the middle'.
//
//  Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1   x=5
//  Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
//
//  Joel Rorseth
//  Created on May 20, 2017
//

#include <iostream>
#include <vector>

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
Node<T> * partition(Node<T> * node, T x) {

    // Initializing these both to the first node establishes the
    // link between head and tail. Then, inserting to the front of
    // head and back of tail maintains this link

    Node<T> * head = node;
    Node<T> * tail = node;

    // Go through every node in original linked list
    while (node != nullptr) {
        Node<T> * current_node_next = node->next;

        // Nodes < x are inserted into head (front), else they
        // are inserted into tail (back)
        if (node->value < x) {
            node->next = head;
            head = node;
        } else {
            tail->next = node;
            tail = node;
        }
        
        node = current_node_next;
    }

    tail->next = nullptr;
    return head;
}

// Demonstration
int main(int argc, char * argv[]) {
    
    Node<int> * head = new Node<int>;
    head->value = 3;
    
    // Generate Linked List using example in description
    std::vector<int> numbers{5, 8, 5, 10, 2, 1};
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        insert_back(head, *it);
    
    std::cout << "Linked List: ";
    print_list(head);
    
    // Returns a new linked list link
    Node<int> * partitioned = partition<int>(head, 5);

    // Output
    std::cout << "\nAfter partitioning about 5...\nLinked List: ";
    print_list(partitioned);
}
