//
//  Cracking the Coding Interview Q8.3
//
//  A magic index in an array A is defined as any i such that A[i] = i.
//  Given a sorted array of distinct integers, find a magic index if 
//  one exists.
//
//  Joel Rorseth
//  Created on October 29, 2017
//

#include <iostream>
#include <vector>

// Because the numbers are sorted, we employ binary search. At any
// index j, if A[j] < j, the magic index must be to the right since
// each leftwards index must decrease by 1 and each number by at least
// 1. Similarly, if A[j] > j, magic index could only appear in left.


// Solution
int magic_index(std::vector<int> & nums, int start, int end) {

    // Base case: Conclude there is no magic index
    if (end < start) return -1;

    auto index = (start + end) / 2;
    auto mid = nums[index];

    // Recurse left or right half
    if (mid == index) return index;
    else if (mid < index) return magic_index(nums, index + 1, end);
    else return magic_index(nums, start, index - 1);
}


int magic_index(std::vector<int> & nums) {
    return magic_index(nums, 0, nums.size() - 1);
}



// Demonstration
int main() {

    std::vector<int> magic{-2,1,3,6,8,9};
    std::cout << "Given [-2,1,3,6,8,9], the magic index is " << 
        magic_index(magic) << std::endl;
}
