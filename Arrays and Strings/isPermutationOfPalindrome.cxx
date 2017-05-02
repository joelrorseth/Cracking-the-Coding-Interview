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
bool isPermutationOfPalindrome(std::string const & str) {

    // Count occurences of each character
    // Only one character (middle of palindrome)
    // should have odd count
    
    std::map<char, int> occ{};
    int oddCount = 0;

    for (auto ch: str) {

        occ[ch] += 1;

        // Found matching character in palindrome
        if (occ[ch] % 2 == 0)
            --oddCount;
        else
            ++oddCount;
    }

    return (oddCount <= 1);
}

// Demonstration
int main(int argc, char * argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <charsequence>" << std::endl;
        exit(0);
    }

    const std::string str{argv[1]};
    auto result = isPermutationOfPalindrome(str);

    if (result)
        std::cout << argv[1] << " is a permutation of a palindrome" << std::endl;
    else
        std::cout << argv[1] << " is not a permutation of a palindrome" << std::endl;
}
