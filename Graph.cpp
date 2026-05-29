#include "Graph.hpp"
#include <algorithm>

Graph::Graph(int xSize, int ySize) {
    // Initialize graph data structures here
    adjacencyList.resize(xSize * ySize); // Assuming a grid graph for visualization purposes
}

void Graph::addNode(float x, float y) {
    // Add a node with an ID and coordinates
    // int nodeId = nodeCoordinates.size(); // Use the current size of nodeCoordinates as the new node ID
    nodeCoordinates.emplace_back(x, y); // Store the coordinates of the new node
}

void Graph::removeNode(int nodeId) {
    // Remove a node and its associated edges
    if (static_cast<size_t>(nodeId) < nodeCoordinates.size()) {
        // remove edges associated with the node
        // remove node from nodeCoordinates
        nodeCoordinates.erase(nodeCoordinates.begin() + nodeId);
    }
}

// void Graph::addEdge(int fromId, int toId, float weight) {
    // Add an edge between two nodes with a weight (for weighted graphs)
    // if (fromId < adjacencyList.size() && toId < adjacencyList.size()) {
        // adjacencyList[fromId].emplace_back(toId, weight); // Add edge from fromId to toId
        // adjacencyList[toId].emplace_back(fromId, weight); // Add edge from toId to fromId (assuming undirected graph)
    // }
// }

void Graph::draw(sf::RenderWindow& window) {
    // Should draw both nodes and edges using SFML shapes and colors, but currently only draws nodes
    std::for_each(nodeCoordinates.begin(), nodeCoordinates.end(), [&](const std::pair<float, float>& coords) {
        sf::CircleShape nodeShape(5); // Example node shape
        nodeShape.setFillColor(sf::Color::Red); // Example node color
        nodeShape.setPosition(coords.first * 20 + 50, coords.second * 20 + 150); // Position based on coordinates (scaled and offset for visualization)
        window.draw(nodeShape);
    });
}

int Graph::nodeAtCoordinates(float x, float y) {
    
    for (size_t i = 0; i < nodeCoordinates.size(); ++i) {
        if (nodeCoordinates[i].first == x && nodeCoordinates[i].second == y) {
            return i; // Return the node ID if coordinates match
        }
    }
    return -1; // Return -1 if no node was found at the given coordinates
}

void Graph::reset() {
    // Method to reset the graph to an empty state (for starting a new visualization)
    adjacencyList.clear();
    nodeCoordinates.clear();
}