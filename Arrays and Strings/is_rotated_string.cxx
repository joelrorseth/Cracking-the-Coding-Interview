//
//  Cracking the Coding Interview Q1.9
//  Given a function is_substring(), determine if a string s2 is
//  a rotation of a string s1, using only one call. For example,
//  "waterbottle" and "erbottlewat" are rotations of eachother
//
//  Joel Rorseth
//  Created on May 9, 2017
//

#include <iostream>

//  Note: If s2 is a rotation of s1, then s1 can be divided into 
//  xy such that yx is s2. Eg. 
//
//      x = wat,  y = erbottle
//      xy = waterbottle,  yx = erbottlewat
//
//  s2 will be a substring in s1s1 if valid rotation
//


// Solution
bool is_rotated_string(std::string const s1, std::string const s2) {

    if ((s1.length() == s2.length()) && s1.length() > 0) {
         auto concatenated = s1 + s1;
         auto retval = concatenated.find(s2);

         // If std::find() does not find substring, string::npos is returned (size_t)
         return (retval == std::string::npos ? false : true);
    }

    return false;
}

// Demonstration
int main(int argc, char * argv[]) {

    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <s1> <s2>" << std::endl;
        exit(0);
    }

    const std::string s1 = argv[1], s2 = argv[2];

    auto retval = is_rotated_string(s1, s2);

    if (retval)
        std::cout << s1 << " and " << s2 << " are rotations of eachother" << std::endl;
    else 
        std::cout << s1 << " and " << s2 << " are not rotations of eachother" << std::endl;
}
