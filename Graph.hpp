#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

// The Graph class represents the data structure used for storing information on nodes, edges, and their relationships.
//This class will be used by the Visualization class to display the graph and its properties.

class Graph {
public:
    Graph(int xSize = 20, int ySize = 20); // Constructor to initialize graph with given dimensions (for visualization purposes)
    // Add methods for adding nodes, edges, etc.
    void addNode(float x, float y); // Add a node with an ID and coordinates
    void addEdge(int fromId, int toId, float weight); // Add an edge between two nodes with a weight (for weighted graphs)
    void removeNode(int nodeId); // Remove a node and its associated edges
    void draw(sf::RenderWindow& window); // Method to draw the graph using SFML (used by Visualization class)
    int nodeAtCoordinates(float x, float y); // Method to get the node ID at given coordinates (for handling mouse clicks in visualization)
    void reset(); // Method to reset the graph to an empty state (for starting a new visualization)
private:
    // Add members for storing graph data
    
    // 2D vector for adjacency list representation of the graph
    // 2D vector for coordinates of nodes (for visualization purposes)
    std::vector<std::vector<std::pair<int, float>>> adjacencyList; // Each pair contains the neighboring node ID and edge weight
    std::vector<std::pair<float, float>> nodeCoordinates; // Each pair contains the relative x and y coordinates of a node to the graph space
    // std::vector<std::vector<int>> myGraph;
};