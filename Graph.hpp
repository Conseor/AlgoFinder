#pragma once
#include <vector>

// The Graph class represents the data structure used for storing information on nodes, edges, and their relationships.
//This class will be used by the Visualization class to display the graph and its properties.

class Graph {
public:
    Graph();
    // Add methods for adding nodes, edges, etc.
    void addNode(float x, float y); // Add a node with an ID and coordinates
    void addEdge(int fromId, int toId, float weight); // Add an edge between two nodes with a weight (for weighted graphs)
private:
    // Add members for storing graph data
    
    // 2D vector for adjacency list representation of the graph
    // 2D vector for coordinates of nodes (for visualization purposes)
    std::vector<std::vector<std::pair<int, float>>> adjacencyList; // Each pair contains the neighboring node ID and edge weight
    std::vector<std::pair<float, float>> nodeCoordinates; // Each pair contains the x and y coordinates of a node
    // std::vector<std::vector<int>> myGraph;
};