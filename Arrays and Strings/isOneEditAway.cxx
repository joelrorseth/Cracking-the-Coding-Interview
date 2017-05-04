//
//  Cracking the Coding Interview Q1.5
//  Determine if two given strings are at most one
//  edit away from eachother. An edit is defined as
//  inserting, removing, or replacing a character.
//
//  Joel Rorseth
//  Created on May 4, 2017
//

#include <iostream>

//  Note: Use two-pointer approach to index through both
//  strings. If a string is longer than another, increment
//  pointer every check, but only increment pointer to shorter
//  string if match found (must keep pointer where it is until
//  match is found at a later point)


// Solution
bool isOneEditAway(std::string const & s1, std::string const & s2) {

    // More than 1 character difference means multiple edits
    auto lengthDifference = s1.length() > s2.length() ? s1.length() - s2.length() : s2.length() - s1.length();
    if (lengthDifference > 1)
        return false;

    // Determine the longer string
    std::string shorter = s1.length() < s1.length() ? s1 : s2;
    std::string longer = s1.length() < s1.length() ? s2 : s1;

    int shorterIndex = 0, longerIndex = 0;
    bool foundDifference = false;

    while (longerIndex < longer.length() && shorterIndex < shorter.length()) {
        
        if (shorter[shorterIndex] != longer[longerIndex]) {

            // At this point, more than one difference
            if (foundDifference)
                return false;

            // Increment difference count
            foundDifference = true;

            // If same length, 'replacement' edit
            // has occured, so move both pointers
            if (shorter.length() == longer.length())
                ++shorterIndex;

        } else {

            // Only move short string index if characters matched
            ++shorterIndex;
        }

        // Important: Longer string pointer is always incremented
        // because it has the 'extra' character causing difference
        ++longerIndex;
    }

    return true;
}

// Demonstration
int main(int argc, char * argv[]) {

    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <string1> <string2>" << std::endl;
        exit(0);
    }

    const std::string str1{argv[1]}, str2{argv[2]};
    auto result = isOneEditAway(str1, str2);

    if (result)
        std::cout << str1 << " and " << str2 << " are one edit away" << std::endl;
    else
        std::cout << str1 << " and " << str2 << " are not one edit away" << std::endl;
}
