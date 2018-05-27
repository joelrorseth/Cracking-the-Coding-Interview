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
bool is_unique_chars(const std::string & str) {

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
        std::cout << "Usage: " << argv[0] << " <charsequence>" << std::endl;
        exit(0);
    }

    auto is_unique = is_unique_chars( argv[1] );
    if (is_unique)
        std::cout << argv[1] << " is unique!" << std::endl;
    else
        std::cout << argv[1] << " is not unique!" << std::endl;
}
