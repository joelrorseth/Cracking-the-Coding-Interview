//
//  Cracking the Coding Interview Q1.3
//  Given string with extra allocated memory,
//  replace spaces with '%20'
//
//  Joel Rorseth
//  Created on May 1, 2017
//

#include <iostream>

//  Note: To perform in place (using C-style char
//  array), start by appending to the rear of the
//  allocated array and reading values from the 'true'
//  end, as to avoid overwriting characters to be read.


// Solution
std::string replace_spaces(std::string const & str, int length) {

    int space_count = 0;
    int new_length;

    // Calculate number of spaces in original string
    for (auto ch: str) 
        if (ch == ' ')
            ++space_count;

    new_length = length + (2 * space_count);

    // Create std::string with enough space for new characters
    std::string result{};
    result.reserve(new_length);

    for (auto ch: str) {

        // If space, replace with '%20' in new string
        if (ch == ' ') {
            result.append("%20");
            new_length += 3;
        
        } else {
            result.push_back(ch);
            new_length += 1;
        }
    }

    return result;
}

// Demonstration
int main(int argc, char * argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " < phrase >" << std::endl;
        exit(0);
    }

    const std::string str{argv[1]};
    std::string result = replace_spaces(str, str.length());

    std::cout << "After replaceSpaces(), the string is:  " << result << std::endl;
}
