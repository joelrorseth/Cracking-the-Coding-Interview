//
//  Cracking the Coding Interview Q3.5
//  Design an algorithm to sort a stack (minimum elements at top).
//
//  Joel Rorseth
//  Created on August 6, 2017
//

#include <iostream>
#include <stack>
#include <deque>

// Solution - O(n^2) time complexity
template <typename T>
void sort_stack(std::stack<T> & stack) {

    std::stack<T> sorted;

    while (!stack.empty()) {

        // Pop off each element from unsorted stack starting from top
        T temp = stack.top();
        stack.pop();

        // Find correct position in sorted stack for new element by
        // removing sorted elements and placing them back on original
        // stack to be sorted again

        while (!sorted.empty() && sorted.top() > temp) {
            stack.push(sorted.top());
            sorted.pop();
        }

        sorted.push(temp);
    }

    // Copy numbers back to original stack (algorithm is not in place)
    while (!sorted.empty()) {
        stack.push(sorted.top());
        sorted.pop();
    }
}


// Demonstration
int main() {

    std::deque<int> data{4,8,1,3,2,9};
    std::stack<int> a(data);

    std::cout << "Original stack (top to bottom):  4,8,1,3,2,9\n"
        << "Sorted (top to bottom): ";

    sort_stack(a);
    while (!a.empty()) {
        std::cout << a.top() << ',';
        a.pop();
    }

    std::cout << std::endl;
}

