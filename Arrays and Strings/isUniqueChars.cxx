//
//  Cracking the Coding Interview Q1.1
//  Test if a given character sequence is a unique
//  combination of ASCII characters
//
//  Joel Rorseth
//  Created on May 1, 2017
//

#include <iostream>

// Solution
bool isUniqueChars(const std::string & str) {

    if (str.length() > 128)
        return false;

    // Use a second array to track characters seen
    bool char_set[128] = { false };

    for (int ch: str) {

        // If true, character has already been found
        if (char_set[ch]) 
            return false;

        char_set[ch] = true;
    }

    return true;
}

// Demonstration
int main(int argc, char * argv[]) {
   
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " < charsequence >" << std::endl;
        exit(0);
    }

    auto isUnique = isUniqueChars( argv[1] );
    if (isUnique)
        std::cout << argv[1] << " is unique!" << std::endl;
    else
        std::cout << argv[1] << " is not unique!" << std::endl;
}
