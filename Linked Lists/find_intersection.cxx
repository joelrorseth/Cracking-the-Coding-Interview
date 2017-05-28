//
//  Cracking the Coding Interview Q2.7
//  Given two singly linked lists, determine if they intersect (based
//  on their reference location). If they do, return the intersecting node.
//
//  1 -> 2 -> 3 
//             \
//               5 -> 7 -> 8     5 is the intersection
//             /
//       4 -> 6
//
//  Joel Rorseth
//  Created on May 28, 2017
//

#include <iostream>

// Solution is easy. Traverse to end, track lengths and compare tail.
// If tails are same, then they intersect. Traverse both again, move start 
// pointer of longer list to same start position using length difference.
// Traverse until node is same, then return.


// MARK: Simple Linked List Implementation (Given)
// Linked List Node
template <typename T>
struct Node {
    
    Node<T> * next = nullptr;
    T value;

    Node<T>(Node<T> * n, T value) : value(value) { next = n; }
    ~Node<T>() { delete next; }
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





// MARK: Solutoion
// Helper for solution
template <typename T>
struct result {

    Node<T> * tail = nullptr;
    int size;

    result(Node<T> * t, int size) :  size(size) { tail = t; }
    ~result() { delete tail; }
};


// Solution
template <typename T>
Node<T> * find_intersection(Node<T> * list1, Node<T> * list2) {

    if (list1 == nullptr || list2 == nullptr) return nullptr;

    result<T> * r1 = get_tail_and_size(list1);
    result<T> * r2 = get_tail_and_size(list2);

    // Identical tails means the lists intersect at some point
    if (r1->tail != r2->tail) return nullptr;

    Node<T> * shorter = r1->size < r2->size ? list1 : list2;
    Node<T> * longer = r1->size < r2->size ? list2 : list1;

    // Advance longer list pointer to position that is equal distance 
    // from the end as the shorter list

    longer = get_kth_node(longer, abs(r1->size - r2->size));

    // Advance both pointers until we find intersection
    // We know this will happen at this point

    while (shorter != longer) {
        shorter = shorter->next;
        longer = longer->next;
    }

    return longer;
}

// Find tail node and length of list
template <typename T>
result<T> * get_tail_and_size(Node<T> * list) {

    if (list == nullptr) return nullptr;

    int size = 1;
    
    // Traverse to end, check next to maintain reference to last element
    while (list->next != nullptr) {
        list = list->next;
        ++size;
    }

    return new result<T>{list, size};
}

template <typename T>
Node<T> * get_kth_node(Node<T> * head, int k) {
    
    for (; k > 0; --k)
        head = head->next;

    return head;
}



// Demonstration
int main() {

    // Create two linked lists, a and b with elements after intersection
    Node<int> * end = new Node<int>{nullptr, 9};
    Node<int> * second_last = new Node<int>{end, 8};
    Node<int> * intersection = new Node<int>{second_last, 7};
    
    Node<int> * a2 = new Node<int>{intersection, 6};
    Node<int> * a = new Node<int>{a2, 5};

    Node<int> * b = new Node<int>{intersection, 4};

    std::cout << "List A: ";
    print_list(a);
    std::cout << "List B: "; 
    print_list(b); 
    
    std::cout << "Intersecting node is " << find_intersection(a, b)->value << std::endl;
}


