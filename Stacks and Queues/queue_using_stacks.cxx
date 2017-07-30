//
//  Cracking the Coding Interview Q3.4
//  Implement a function queue using no more than two stacks.
//
//  Joel Rorseth
//  Created on July 29, 2017
//

#include <iostream>
#include <stack>


// Solution
template <typename T>
class stack_queue {

private:
    std::stack<T> main, temp;

    // Shift stack elements from actual stack temp
    void shift_stacks() {
        if (temp.empty())
            while (!main.empty()) {
                temp.push( main.top() );
                main.pop();
            }
    }

public:

    // This approach uses one normal stack and a backup for retrieval
    // Push all elements (thus reversing), and pick from top for oldest

    stack_queue<T>() : main{}, temp{} {}

    int size() { return main.size() + temp.size(); }

    bool empty() { return (main.empty() && temp.empty()); }

    void add(T value) { main.push(value); }

    // Peek requires shifting all elements to second stack
    // This retrieves the oldest element in stack (first out!)
    
    T peek() { 
        shift_stacks();
        return temp.top();
    }

    // Removing an element works the same way as peek
    // Elements could be shifted back, but don't need to quite yet

    T remove() {
        shift_stacks();

        auto top = temp.top();
        temp.pop();

        return top;
    }
};


// Demonstration
int main() {

    stack_queue<int> a{};
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);

    std::cout << "After adding 1, 2, 3, 4 in sequence to the queue,\n"
        << "Dequeueing one at a time yeilds:  ";

    while (!a.empty()) 
        std::cout << a.remove() << ',' << ' ';
    std::cout << std::endl;
}
