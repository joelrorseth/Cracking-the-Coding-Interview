//
//  Cracking the Coding Interview Q2.8
//  Given a circular linked list, return the node at the beginning of
//  the loop / cycle. If no cycle, return null.
//
//  Joel Rorseth
//  Created on June 14, 2017
//

#include <iostream>


// MARK: Simple Linked List Implementation (Given)
// Linked List Node
template <typename T>
struct Node {

    Node<T> * next = nullptr;
    T value;

    Node<T>() : value(0), next(nullptr) {}
    Node<T>(Node<T> * n, T value) : value(value) { next = n; }
    ~Node<T>() { delete next; }
};



// Solution
template <typename T>
Node<T> * find_loop_beginning(Node<T> * head) {

    Node<T> * slow = head;
    Node<T> * fast = head;

    // Advance fast ptr to last node or one past (nullptr)
    // Slow will point to middle element
    while (fast  && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        // A circular list will never end (with nullptr), thus break
        // when fast 'laps' slow and they collide! Easy!
        if (slow == fast) break;
    }
    
    // Circular list will never contain nullptr
    if (!fast || !fast->next) return nullptr;

    
    // The distance from head to cycle beginning is the same as the
    // distance of the fast to the end / beginning
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}



// Demonstration
int main() {

    Node<int> * l3 = new Node<int>{};
    Node<int> * l6 = new Node<int>{l3, 6};
    Node<int> * l5 = new Node<int>{l6, 5};
    Node<int> * l4 = new Node<int>{l5, 4};
    Node<int> * l2 = new Node<int>{l3, 2};
    Node<int> * l1 = new Node<int>{l2, 1};

    l3->next = l4;
    l3->value = 3;

    std::cout << "Linked list:  1->2->3->4->5->6\n" << 
        "                    ^________|\n\n" << "Beginning of cycle: "
        << find_loop_beginning(l1)->value << std::endl;
}
