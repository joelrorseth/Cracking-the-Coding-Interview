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
bool is_one_edit_away(std::string const & s1, std::string const & s2) {

    // More than 1 character difference means multiple edits
    auto length_difference = s1.length() > s2.length() ? s1.length() - s2.length() : s2.length() - s1.length();
    if (length_difference > 1)
        return false;

    // Determine the longer string
    std::string shorter = s1.length() < s1.length() ? s1 : s2;
    std::string longer = s1.length() < s1.length() ? s2 : s1;

    int shorter_index = 0, longer_index = 0;
    bool found_difference = false;

    while (longer_index < longer.length() && shorter_index < shorter.length()) {
        
        if (shorter[shorter_index] != longer[longer_index]) {

            // At this point, more than one difference
            if (found_difference)
                return false;

            // Increment difference count
            found_difference = true;

            // If same length, 'replacement' edit
            // has occured, so move both pointers
            if (shorter.length() == longer.length())
                ++shorter_index;

        } else {

            // Only move short string index if characters matched
            ++shorter_index;
        }

        // Important: Longer string pointer is always incremented
        // because it has the 'extra' character causing difference
        ++longer_index;
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
    auto result = is_one_edit_away(str1, str2);

    if (result)
        std::cout << str1 << " and " << str2 << " are one edit away" << std::endl;
    else
        std::cout << str1 << " and " << str2 << " are not one edit away" << std::endl;
}
