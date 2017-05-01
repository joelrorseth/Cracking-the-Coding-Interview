//
//  Cracking the Coding Interview Q1.2 
//  Test if two given strings are valid
//  permutations of eachother
//
//  Joel Rorseth
//  Created on May 1, 2017
//

#include <iostream>

// Solution
bool isPermutation(const std::string & s, const std::string & t) {
    
    if (s.length() != t.length())
        return false;
    
    // Makes copies to avoid changing passed strings
    std::string s1 = s;
    std::string s2 = t;

    // Sort characters alphabetically
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    // If identical, then valid permutation!
    return s1 == s2;
}

// Demonstration
int main(int argc, char * argv[]) {

    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <string1> <string2>" << std::endl;
        exit(0);
    }

    auto result = isPermutation(argv[1], argv[2]);

    if (result)
        std::cout << argv[1] << " and " << argv[2] 
            << " are valid permutations of eachother" << std::endl;
    else 
        std::cout << argv[1] << " and " << argv[2]
            << " are not permutations of eachother" << std::endl;
}
