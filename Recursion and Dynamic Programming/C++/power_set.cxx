//
//  Cracking the Coding Interview Q8.4
//  Compute the power set (all subsets) of a set.
//
//  Joel Rorseth
//  Created on November 2, 2017
//

#include <iostream>
#include <vector>


// Build up a solution from the base cases. Each non-trivial case
// is the previous case combined with the previous case with the 
// new element added in.
//
// P(0) = {}
// P(1) = {}, {a1}
// P(2) = {}, {a1}, {a2}, {a1,a2}
//
// P(3) = P(2) + (P(2) with a3 added to each subset)
// P(3) = {}, {a1}, {a2}, {a1,a2}, {a3}, {a1,a3}, {a2,a3}, {a1,a2,a3}



// Solution
std::vector<std::vector<int>> powerset(std::vector<int> set, int i) {

    std::vector<std::vector<int>> subsets;

    if (set.size() == i) {
        subsets.push_back({});
    
    } else {

        // Recursively obtain powerset starting at the end element
        subsets = powerset(set, i+1);

        // Get the next element to add into recursively obtained powerset
        auto item = set[i];


        std::vector<std::vector<int>> more_subsets;

        // Clone all subsets found so far and add new element into each
        for (const auto & subset: subsets) {
            
            std::vector<int> new_subset{subset};
            new_subset.push_back(item);

            more_subsets.push_back(new_subset);
        }

        // Merge cloned subsets with new element into original powerset
        // This will be the basis for cloning on the next iteration

        for (const auto & subset: more_subsets)
            subsets.push_back(subset);
    }

    return subsets;
}



// Demonstration
int main() {

    std::vector<int> sets{1, 4, 6, 2};
    std::cout << "Set: {1, 4, 6, 2}\nPowerset: ";

    for (const auto & subset: powerset(sets, 0)) {

        std::cout << '{';
        for (const auto & element: subset) 
            std::cout << element << ',';
        std::cout << "}, ";
    }

    std::cout << std::endl;
}
