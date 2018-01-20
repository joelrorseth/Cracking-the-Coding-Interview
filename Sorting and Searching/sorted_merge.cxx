//
//  Cracking the Coding Interview Q10.1
//  Given two sorted arrays A and B, where A has sufficient extra space
//  to hold B appended, merge B into A in sorted order.
//
//  Joel Rorseth
//  Created on January 20, 2018
//

#include <iostream>
#include <vector>


// Start two 'pointers' at the END of both arrays. Compare these two elements
// (largest in each) and sequentially put largest at END of ALLOCATED array.

void merge(std::vector<int> & a, std::vector<int> & b, int lastA, int lastB) {

    auto indexA = lastA - 1;
    auto indexB = lastB - 1;

    // Calculate end of merged array
    int merged_index = lastB + lastA - 1;

    while (indexB >= 0) {

        // Determine which largest element of A/b is the largest
        if (indexA >= 0 && a[indexA] > b[indexB]) {
            a[merged_index] = a[indexA];
            --indexA;
        
        } else {

            a[merged_index] = b[indexB];
            --indexB;
        }

        --merged_index;
    }
}


void print(const std::vector<int> & array) {
    for (const auto e: array)
        std::cout << e << ", ";
    std::cout << std::endl;
}

// Demonstration
int main() {

    // A is assumed to have allocated extra space, fill with -1
    // We are using a variable to track array endings anyways

    std::vector<int> a{2, 9, 15, 34, -1, -1, -1, -1};
    std::vector<int> b{4, 16, 18, 22};
   
    std::cout << "*Note: -1 indicates allocated, empty space.*\n\n";
    std::cout << "A = ";
    print(a);
    std::cout << "B = ";
    print(b);
    
    std::cout << "Merged into A  = ";
    merge(a, b, 4, b.size());
    print(a);
}
