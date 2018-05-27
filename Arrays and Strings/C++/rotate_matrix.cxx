//
//  Cracking the Coding Interview Q1.7
//  Given an N x N image matrix, where each pixel
//  is 4 bytes, rotate the image 90 degrees.
//
//  Joel Rorseth
//  Created on May 6, 2017
//

#include <iostream>
#include <vector>

//  Note: Each layer needs to be rotated by copying each of
//  its elements (except the last) to its new spot after rotation
//
//  A A A A   Ex. For 4x4 matrix, there are two layers (A and B here)
//  A B B A   For smaller matrices such as 3x3, there is only one layer
//  A B B A   to be rotated because a single element layer won't change.
//  A A A A
//

// Convenience function to print 2D matrix
template <typename T>
void print_matrix(std::vector<std::vector<T>> matrix) {

    for (auto vect: matrix) {
        for (auto element: vect)
            std::cout << element << '\t';
        std::cout << '\n';
    }
}

// Solution
template <typename T>
void rotate_matrix(std::vector<std::vector<T>> & matrix, int n) {

    for (int layer = 0; layer < n/2; ++layer) {
        
        // Calculate indexes for this layer
        int first = layer;
        int last = n - 1 - layer;

        // Loop through and move all elements in each row except the last! 
        // The last element will already be correct due to first move

        for (int i = first; i < last; ++i) {
            int offset = i - first;

            int top = matrix[first][i];

            // Left -> Top
            matrix[first][i] = matrix[last - offset][first];

            // Bottom -> Left
            matrix[last - offset][first] = matrix[last][last - offset];

            // Right -> Bottom
            matrix[last][last - offset] = matrix[i][last];

            // Top -> Right
            matrix[i][last] = top;

            /*
            // Uncomment to see each step
            std::cout << '\n';
            print_matrix(matrix);
            */
        }
    }
}

// Demonstration
int main(int argc, char * argv[]) {

    std::vector<std::vector<int>> a{
        {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}
    };

    std::cout << "Original matrix..." << std::endl;
    print_matrix(a);

    rotate_matrix(a, a.size());

    std::cout << "\nRotated  matrix..." << std::endl;
    print_matrix(a);
}
