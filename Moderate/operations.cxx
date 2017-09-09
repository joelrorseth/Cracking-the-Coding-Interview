//
//  Cracking the Coding Interview Q16.9
//  Implement methods to subtract, multiply and divide integers
//  while only using the addition operator.
//
//  Joel Rorseth
//  Created on September 9, 2017
//

#include <iostream>
#include <climits>

// Flip sign
int negate(int number) {

    int negated = 0;
    int sign = number < 0 ? 1 : -1;

    // Add 1 or -1 'number' times to invert sign
    while (number != 0) {
        number += sign;
        negated += sign;
    }

    return negated;
}


// Subtract
int subtract(int a, int b) {
    return a + negate(b);
}


// Absolute value
int abs(int number) {

    if (number < 0) return negate(number);
    else return number;
}


// Multiply by adding a to itself b times
int multiply(int a, int b) {

    // Optimize for loop for less repititions
    if (b < a) return multiply(b, a);

    int sum = 0;
    for (int i = abs(b); i > 0; i = subtract(i, 1)) 
        sum += a;

    // Negative numbers are treated as pos
    // Reapply sign here
    if (b < 0) sum = negate(sum);

    return sum;
}


// Divide
int divide(int a, int b) {

    // Division by 0 is illegal
    if (b == 0) return INT_MIN;

    int absa = abs(a);
    int absb = abs(b);
    int product = 0;
    int x = 0;

    while (product + absb <= absa) {
        product += absb;
        ++x;
    }

    // Negative numbers have been trated as pos thus far
    // Convert them back (eg neg * neg == pos etc)
    if ((a < 0 && b < 0) || (a > 0 && b > 0)) return x;
    else return negate(x);
}


// Demonstration
int main() {

    std::cout << "10-5=" << subtract(10,5) << "\n10*5=" << multiply(10,5)
        << "\n10/5=" << divide(10,5) << std::endl;
}
