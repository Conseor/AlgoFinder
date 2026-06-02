#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

// The Graph class represents the data structure used for storing information on nodes, edges, and their relationships.
//This class will be used by the Visualization class to display the graph and its properties.

class Graph {
public:
    Graph(int xSize = 20, int ySize = 20); // Constructor to initialize graph with given dimensions (for visualization purposes)
    // Add methods for adding nodes, edges, etc.
    void addNode(int x, int y); // Add a node with an ID and coordinates
    void addEdge(int fromId, int toId, float weight); // Add an edge between two nodes with a weight (for weighted graphs)
    void removeNode(int nodeId); // Remove a node and its associated edges
    void removeEdge(int fromId, int toId); // Remove an edge between two nodes
    void draw(sf::RenderWindow& window); // Method to draw the graph using SFML (used by Visualization class)
    int nodeAtCoordinates(int x, int y); // Method to get the node ID at given coordinates (for handling mouse clicks in visualization)
    void reset(); // Method to reset the graph to an empty state (for starting a new visualization)
    void selectNode(int nodeId) { selectedNodeId = nodeId; selectedEdgeToId = -1;} // Method to set the currently selected node (for visualization purposes)
    int getSelectedNodeId() const { return selectedNodeId; } // Method to get the currently selected node ID (for visualization purposes)
    std::pair<int, int> getNodeCoordinates(int nodeId) const { return nodeCoordinates[nodeId]; } // Method to get the coordinates of a node by its ID (for visualization purposes)
    void getNextEdge();
    void getPreviousEdge();
private:
    // Add members for storing graph data
    
    // 2D vector for adjacency list representation of the graph
    // 2D vector for coordinates of nodes (for visualization purposes)
    std::vector<std::vector<int>> adjacencyList; // Each pair contains the neighboring node ID and edge weight
    std::vector<std::pair<int, int>> nodeCoordinates; // Each pair contains the relative x and y coordinates of a node to the graph space
    // std::vector<std::vector<int>> myGraph;
    int selectedNodeId = -1; // To keep track of the currently selected node (for visualization purposes)
    int selectedEdgeToId = -1; // To keep track of the currently selected edge's destination node ID (for visualization purposes)
    void drawNodeInformation(sf::RenderWindow& window, int nodeId); // Method to draw information about a node (used in visualization when a node is selected)
    void drawEdgeInformation(sf::RenderWindow& window, int fromId, int toId, float weight); // Method to draw information about an edge (used in visualization when an edge is selected)
    void drawEdge(sf::RenderWindow& window, int fromId, int toId, float weight); // Method to draw an edge between two nodes (used in visualization)
    int xSize; // Size of the graph in the x direction (for visualization purposes)
    int ySize; // Size of the graph in the y direction (for visualization purposes)
};