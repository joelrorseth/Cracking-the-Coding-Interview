//
//  Cracking the Coding Interview Q4.1
//  Given a directed graph, determine if a route exists between 
//  two nodes. 
//
//  Joel Rorseth
//  Created on August 13, 2017
//

#include <iostream>
#include <queue>
#include <vector>


enum State { unvisited, visited, visiting };

// Simple Node class for adjacency list graph representation
class Node {
    private:
        State state;
        std::string name;
        std::vector<Node> adjacent;
    public:
        State get_state() const { return state; }
        std::string get_name() const { return name; }
        
        void set_state(State s) { state = s; }
        void set_name(std::string n) { name = n; }

        void add_adjacent(Node & node) 
            { adjacent.push_back(node); };

        std::vector<Node> get_adjacent() { return adjacent; }

        bool operator==(Node const & node) const 
            { return name == node.name; }

        Node() : name("Temp"), state(unvisited) {}
        Node(std::string s) : name(s), state(unvisited) {}
};

// Simple Graph class represented as a collection of vertices (nodes)
class Graph {
    private:
        std::vector<Node> nodes;
    public:
        void add_node(Node & node) { nodes.push_back(node); }
        Graph(std::vector<Node> const & n) : nodes(n) {}
};



// Solution
// Breadth first search to find an existing path
bool search(Graph g, Node start, Node end) {
    if (start == end) return true;

    std::queue<Node> bfs_queue;

    // Add the starting node to bfs queue
    start.set_state(visiting);
    bfs_queue.push(start);


    // Go through each node's adjacent nodes in sequence using the queue
    // Using a queue, we check all neighbours before moving to n+1 depth
    while (!bfs_queue.empty()) {
    
        auto temp = bfs_queue.front();
        bfs_queue.pop();
        
        // Check all adjacent nodes, add to queue if not the 'end'
        for (Node & adj: temp.get_adjacent()) {
            if (adj.get_state() == unvisited) {
                
                // If end node has been reached, then path was formed
                if (adj == end)
                    return true;
                else {
                    adj.set_state(visiting);
                    bfs_queue.push(adj);
                }
            }
        }

        temp.set_state(visited);
    }

    return false;
}



// Demonstration
int main() {

    Node n1("1");
    Node n2("2");
    Node n3("3");
    Node n4("4");
    Node n5("5");
    Node n6("6");

    n4.add_adjacent(n5);
    n3.add_adjacent(n6);
    n3.add_adjacent(n4);
    n1.add_adjacent(n2);
    n1.add_adjacent(n3);

    std::vector<Node> nodes{n1,n2,n3,n4,n5,n6};
    Graph graph(nodes);

    auto exists = search(graph, n1, n6);

    std::cout << "Given a directed graph:  1->2, 1->3, 3->4, 3->6, 4->5\n";
    std::cout << "A path from 1 to 6 does " <<
        ((exists) ? "" : "not ") << "exist." << std::endl;
}
