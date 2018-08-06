//
//  Cracking the Coding Interview Q8.1
//
//  A child is running up steps. He can hop either 1, 2, or 3 steps
//  at a time. Determine how many possible ways the child can run up 
//  the steps.
//
//  Joel Rorseth
//  Created on October 26, 2017
//

#include <iostream>
#include <vector>


// Recursive solution
int count_ways(int n, std::vector<int> & memory) {

    // Path is not possible, n went beyond first step in this recursion
    if (n < 0) { return 0; }      

    // Return one if this recursed path can exist
    else if (n == 0) { return 1; }

    // Check cached values to avoid recalculating repeated cases
    else if (memory[n] > -1) { return memory[n]; }

    else { 
        // Cache it then return
        memory[n] = count_ways(n-1, memory) + 
            count_ways(n-2, memory) + count_ways(n-3, memory); 

        return memory[n];
    }
}


// Solution starts here, passes vector to use memoization
int count_ways(int n) {
    std::vector<int> memory(n+1, -1);
    return count_ways(n, memory);
}



// Demonstration
int main() {

    std::cout << "There are " << count_ways(6) << " ways to climb 6 stairs."
        << std::endl;
}
