//
//  Cracking the Coding Interview Q2.6
//  Determine if a singly linked list is a palindrome.
//
//  Joel Rorseth
//  Created on May 23, 2017
//

#include <iostream>
#include <stack>

// This problem is easily solved using a stack. Push every element up
// until the midpoint, then pop one at a time and compare as you traverse
// the remaining list. If odd # elements, skip middle element.


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
 


// Solution (Two Runner Approach)
template <typename T>
bool is_palindrome(Node<T> * head) {

    Node<T> * fast = head;
    Node<T> * slow = head;

    std::stack<int> stack{};

    // Move slow to the midpoint of list, fast to the end
    // This is achieved by moving fast twice as fast!

    while (fast != nullptr && fast->next != nullptr) {
        stack.push(slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }

    // If odd # elements, slow will need to advance one element
    // This is because the middle element exactly will only appear once

    if (fast != nullptr)
        slow = slow->next;

    // Pop one value at a time, compare to slow element
    // The stack should be empty, all elements would match when popped

    while (slow != nullptr) {
        if (stack.top() != slow->value)
            return false;

        stack.pop();
        slow = slow->next;
    }

    return true;
}


// Demonstration
int main() {

    Node<int> * palindrome = new Node<int>;

    palindrome->value = 0;
    insert_back(palindrome, 1);
    insert_back(palindrome,  2);
    insert_back(palindrome, 3);
    insert_back(palindrome, 3);
    insert_back(palindrome, 2);
    insert_back(palindrome, 1);
    insert_back(palindrome, 0);

    std::cout << "List:   ";
    print_list(palindrome);

    std::cout << "is_palindrome(List) = " 
        << (is_palindrome(palindrome) ? "true" : "false") << std::endl;
}
