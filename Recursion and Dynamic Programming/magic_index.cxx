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


// Solution for sorted array, distinct integers
int magic_index_distinct(std::vector<int> & nums, int start, int end) {

    // Base case: Conclude there is no magic index
    if (end < start) return -1;

    auto index = (start + end) / 2;
    auto mid = nums[index];

    // Recurse left or right half
    if (mid == index) return index;
    else if (mid < index) return magic_index_distinct(nums, index + 1, end);
    else return magic_index_distinct(nums, start, index - 1);
}



// If any non-magic A[j] is obtained, for non-distinct integers, we know
// we can skip over any indices between j and A[j]. Thus for every check,
// we can eliminate a range on one side (because they are still sorted!)


// Solution for sorted array, non-distinct integers
int magic_index(std::vector<int> & nums, int start, int end) {

    if (end < start) return -1;

    auto index = (start + end) / 2;
    auto mid = nums[index];

    if (mid == index) return index;

    // Search left
    auto left_index = std::min(index - 1, mid);
    auto left = magic_index(nums, start, left_index);

    // Avoid returning -1 until we check right side too
    if (left >= 0) return left;

    // Search right
    auto right_index = std::max(index + 1, mid);
    return magic_index(nums, right_index, end);
}



int magic_index_distinct(std::vector<int> & nums) {
    return magic_index_distinct(nums, 0, nums.size() - 1);
}

int magic_index(std::vector<int> & nums) {
    return magic_index(nums, 0, nums.size() - 1);
}



// Demonstration
int main() {

    std::vector<int> distinct{-2,1,3,6,8,9};
    std::vector<int> nondistinct{-3,-3,1,2,4,4,6};

    std::cout << "Given [-2,1,3,6,8,9], the magic index is " << 
        magic_index_distinct(distinct) << std::endl;
 
    std::cout << "Given [-3,-3,1,2,4,4,6], the magic index is " << 
        magic_index(nondistinct) << std::endl;
}
