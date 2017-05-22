//
//  Cracking the Coding Interview Q2.5
//  Given two linked lists representing two integers (stored in reverse
//  digit order), return the sum of the two numbers as a linked list
//  (also in reverse).
//
//  List A:  7 -> 1 -> 6      617
//  List B:  5 -> 9 -> 2    + 295
//  ------------------------------
//  Output:  2 -> 1 -> 9      912
//
//  Joel Rorseth
//  Created on May 22, 2017
//

#include <iostream>
#include <vector>

// Solution is straightforward. Perform addition as you would on paper
// by adding each column, carrying over digits to the next place value.
// Since stored in reverse, this can instead be done left to right.


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
Node<T> * sum_lists(Node<T> * a, Node<T> * b, T carry) {

    // Base case (no more digits or carry over)
    if (a == nullptr && b == nullptr && carry == 0)
        return nullptr;

    Node<T> * result = new Node<T>;
    T column_sum = carry;

    // Add digits (if any) in current column and carry from pervious column
    if (a != nullptr)
        column_sum += a->value;
    if (b != nullptr)
        column_sum += b->value;

    // Assign this place value the single (ones) digit
    result->value = column_sum % 10;

    // If there is at least one digit remaining, add next digit(s)
    if (a != nullptr || b != nullptr) {
        Node<T> * next = sum_lists( a == nullptr ? nullptr : a->next,
                                    b == nullptr ? nullptr : b->next,
                                    column_sum >= 10 ? 1 : 0);
        result->next = next;
    }

    return result;
}


// Demonstration
int main() {

    Node<int> * a = new Node<int>;
    Node<int> * b = new Node<int>;

    a->value = 7;
    b->value = 5;

    insert_back(a, 1);
    insert_back(a, 6);
    insert_back(b,  9);
    insert_back(b, 2);

    std::cout << "List A:   ";
    print_list(a);
    std::cout << "List B:   ";
    print_list(b);

    std::cout << "----------------------------------\nSum:      ";
    print_list(sum_lists(a, b, 0));
}
