//
//  Cracking the Coding Interview Q8.2
//
//  Given a grid of 1's and 0's, determine the path for a robot 
//  positioned at the top left (0,0) to the bottom right of the grid.
//  The robot can only move right and down, and on 1's only.
//
//  Joel Rorseth
//  Created on October 28, 2017
//

// Should use unordered_map for O(1) memoization lookup, but its a pain in the ass 
// In C++ you would have to implement hash function for a std::pair (Point)

#include <map>
#include <iostream>
#include <vector>
#include <utility>

using Maze = std::vector<std::vector<int>>;
using Point = std::pair<int, int>;
using Cache = std::map<Point, bool>;



// Solution: Recursive with DP/Memoization
bool get_path(Maze & maze, int row, int col, std::vector<Point> & path, Cache & cache) {
    
    // Base Case: Avoid backwards traversal past bounds
    // Rule: Robot cannot step on 0's
    if (row < 0 || col < 0 || !maze[row][col]) return false;

    // Check map of currently memoized points to their possibility of being reachable
    Point current_point{row, col};
    if (cache.find(current_point) != cache.end()) 
        return cache[current_point];

    bool at_origin = row == 0 && col == 0;
    bool path_exists = false;

    // True if we have arrived at origin or path can be found to origin recursively
    if (at_origin || get_path(maze, row-1, col, path, cache) || get_path(maze, row, col-1, path, cache)) {

        path.push_back({row, col});
        path_exists = true;
    }
     
    cache[current_point] = path_exists;
    return path_exists;
}



// Solution: Starting point
void get_path(Maze & maze, std::vector<Point> & path, Cache & cache) {

    auto maze_size = maze.size();
    if (!maze_size) 
        std::cout << "Error: Maze is empty" << std::endl;

    // Recursively determine if bottom right corner can be reached
    if (!get_path(maze, maze_size-1, maze_size-1, path, cache))
        std::cout << "No path exists!" << std::endl;
}



// Demonstration
int main() {

    Maze maze{
        {1,0,0,1,1,1},
        {1,0,1,1,0,0},
        {1,1,0,0,0,0},
        {0,1,0,1,1,0},
        {0,1,1,1,1,1},
        {0,0,1,0,0,1}
    };

    std::cout << "Maze:\n";
    for (auto & row: maze) {
        for (auto cell: row)
            std::cout << cell << ' ';
        std::cout << '\n';
    }

    std::cout << "\nFinding path:\n";

    std::vector<Point> path{};
    Cache cache{};
    get_path(maze, path, cache);

    for (auto & point: path)
        std::cout << point.first << ',' << point.second << " -> ";
    std::cout << std::endl;
}
