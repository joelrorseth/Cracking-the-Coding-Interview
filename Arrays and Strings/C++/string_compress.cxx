//
//  Cracking the Coding Interview Q1.6
//  Implement a string compression algorithm using
//  counts of repeated characters. Eg. abbccccdeeaa
//  -> a1b2c4d1e2a2. If compressed string is not 
//  smaller, return original string.
//
//  Joel Rorseth
//  Created on May 4, 2017
//

#include <iostream>

// Solution
std::string string_compress(std::string const & str) {

    std::string retval{};

    int count = 0, pos = 0;
    char hold;

    for (auto ch: str) {

        // If another consecutive character, increment count
        if (ch == hold) {
            ++count;
        } else {

            // Prevent printing character in first iteration
            // Append current character and count to string
            if (pos != 0) {
                retval.push_back(hold);
                retval.push_back(count + '0');
            }

            // Reset count, change hold to new character
            hold = ch;
            count = 1;
        }

        ++pos;
    }

    // After last loop iteration, character is still in hold
    retval.push_back(hold);
    retval.push_back(count + '0');

    return (retval.length() < str.length() ? retval : str);
}

// Demonstration
int main(int argc, char * argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " < phrase >" << std::endl;
        exit(0);
    }

    const std::string str{argv[1]};
    std::string result = string_compress(str);

    std::cout << "After stringCompress(), smallest string is: " << result << std::endl;
}

