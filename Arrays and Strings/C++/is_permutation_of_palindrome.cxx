//
//  Cracking the Coding Interview Q1.4
//  Determine if a given string is a permutation
//  of a palindrome eg. "tactcoa" -> true
//
//  Joel Rorseth
//  Created on May 2, 2017
//

#include <iostream>
#include <map>

// Solution
bool is_permutation_of_palindrome(std::string const & str) {

    // Count occurences of each character
    // Only one character (middle of palindrome)
    // should have odd count
    
    std::map<char, int> occ{};
    int odd_count = 0;

    for (auto ch: str) {

        occ[ch] += 1;

        // Found matching character in palindrome
        if (occ[ch] % 2 == 0)
            --odd_count;
        else
            ++odd_count;
    }

    return (odd_count <= 1);
}

// Demonstration
int main(int argc, char * argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <charsequence>" << std::endl;
        exit(0);
    }

    const std::string str{argv[1]};
    auto result = is_permutation_of_palindrome(str);

    if (result)
        std::cout << argv[1] << " is a permutation of a palindrome" << std::endl;
    else
        std::cout << argv[1] << " is not a permutation of a palindrome" << std::endl;
}
