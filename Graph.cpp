#include "Graph.hpp"
#include "Colors.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

Graph::Graph(int xSize, int ySize): xSize(xSize), ySize(ySize) {
    // Initialize graph data structures here
    adjacencyList = std::vector<std::vector<int>>(xSize, std::vector<int>(ySize, -1));
    // for (auto& row : adjacencyList) {
    //     std::fill(row.begin(), row.end(), -1); // Initialize all edge weights to -1 (no edges)
    // }
}

void Graph::addNode(int x, int y) {
    // Add a node with an ID and coordinates
    // int nodeId = nodeCoordinates.size(); // Use the current size of nodeCoordinates as the new node ID
    if (nodeAtCoordinates(x, y) == -1) { // Check if a node already exists at the given coordinates
        nodeCoordinates.emplace_back(x, y); // Store the coordinates of the new node
    }
}

void Graph::removeNode(int nodeId) {
    // Remove a node and its associated edges
    if (static_cast<size_t>(nodeId) < nodeCoordinates.size()) {
        // remove edges associated with the node
        // remove node from nodeCoordinates
        nodeCoordinates.erase(nodeCoordinates.begin() + nodeId);
    }
}

void Graph::addEdge(int fromId, int toId, float weight) {
    // Add an edge between two nodes with a weight (for weighted graphs)
    if (static_cast<size_t>(fromId) < adjacencyList.size() && static_cast<size_t>(toId) < adjacencyList.size()) {
        adjacencyList.at(fromId).at(toId) = weight;
    }
}

void Graph::removeEdge(int fromId, int toId) {
    // Remove an edge between two nodes
    if (static_cast<size_t>(fromId) < adjacencyList.size() && static_cast<size_t>(toId) < adjacencyList.size()) {
        adjacencyList.at(fromId).at(toId) = -1; // Set weight to -1 to indicate no edge
    }
}

void Graph::draw(sf::RenderWindow& window) {
    // Should draw both nodes and edges using SFML shapes and colors, but currently only draws nodes

    // Draw Nodes
    sf::CircleShape nodeShape(5); // Example node shape
    nodeShape.setOrigin(5, 5); // Set origin to center for proper positioning
    std::for_each(nodeCoordinates.begin(), nodeCoordinates.end(), [&](const std::pair<int, int>& coords) {
        sf::CircleShape nodeShape(5); // Example node shape
        nodeShape.setFillColor(sf::Color::Red); // Example node color
        nodeShape.setPosition(coords.first * 20 + 50, coords.second * 20 + 150); // Position based on coordinates (scaled and offset for visualization)
        window.draw(nodeShape);
    });
    
    if (selectedNodeId != -1) {
        drawNodeInformation(window, selectedNodeId); // Draw node information when a node is drawn (for demonstration purposes)
        drawEdgeInformation(window, selectedNodeId, selectedEdgeToId, adjacencyList[selectedNodeId][selectedEdgeToId]); // Example of drawing edge information for the selected node (for demonstration purposes)
    }
    // Draw Edges

    for (int i = 0; i < static_cast<int>(adjacencyList.size()); i++) {
        for (int j = 0; j < static_cast<int>(adjacencyList[i].size()); j++) {
            if (adjacencyList[i][j] != -1) { // Check if an edge exists
                drawEdge(window, i, j, adjacencyList[i][j]); // Draw the edge with its weight
            }
        }
    }
}

int Graph::nodeAtCoordinates(int x, int y) {
    
    for (size_t i = 0; i < nodeCoordinates.size(); ++i) {
        if (nodeCoordinates[i].first == x && nodeCoordinates[i].second == y) {
            return i; // Return the node ID if coordinates match
        }
    }
    return -1; // Return -1 if no node was found at the given coordinates
}

void Graph::reset() {
    // Method to reset the graph to an empty state (for starting a new visualization)
    adjacencyList = std::vector<std::vector<int>>(xSize, std::vector<int>(ySize, -1));
    nodeCoordinates.clear();
    selectedNodeId = -1; // Reset selected node ID
    selectedEdgeToId = -1; // Reset selected edge destination node ID
}
void Graph::drawEdge(sf::RenderWindow& window, int fromId, int toId, float weight) {
    // Method to draw an edge between two nodes (used in visualization)
    if (static_cast<size_t>(fromId) < nodeCoordinates.size() && static_cast<size_t>(toId) < nodeCoordinates.size()) {
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(nodeCoordinates[fromId].first * 20 + 55, nodeCoordinates[fromId].second * 20 + 155), sf::Color::Blue), // Example edge color
            sf::Vertex(sf::Vector2f(nodeCoordinates[toId].first * 20 + 55, nodeCoordinates[toId].second * 20 + 155), sf::Color::Blue)
        };
        window.draw(line, 2, sf::Lines);

        // Draw arrow to indicate direction of edge (for directed graphs)
        int arrowSize = 5;
        sf::CircleShape arrow(arrowSize, 3);
        arrow.setOrigin(arrowSize, arrowSize / 4); // Set origin to center of the base of the triangle for proper positioning
        arrow.setFillColor(sf::Color::Blue); // Example edge color
        // Position and rotate the arrow based on the direction of the edge
        float angle = atan2(nodeCoordinates[toId].second - nodeCoordinates[fromId].second, nodeCoordinates[toId].first - nodeCoordinates[fromId].first);
        arrow.setPosition(nodeCoordinates[toId].first * 20 + 55, nodeCoordinates[toId].second * 20 + 155);
        arrow.setRotation(angle * 180 / 3.14159f + 90);
        window.draw(arrow);
    }
}

void Graph::drawNodeInformation(sf::RenderWindow& window, int nodeId) {
    // Method to draw information about a node (used in visualization when a node is selected)
    if (static_cast<size_t>(nodeId) < nodeCoordinates.size()) {
        // Draw information about the node (e.g., ID, coordinates, etc.)
        // This is just a placeholder implementation and can be expanded to show more details
        sf::Font font;
        if (!font.loadFromFile("Aloevera.ttf")) {
            // Handle error loading font
            return;
        }
        sf::Text text;
        text.setFont(font);
        text.setString("Node ID: " + std::to_string(nodeId) + "\nCoordinates: (" + std::to_string(nodeCoordinates[nodeId].first) + ", " + std::to_string(nodeCoordinates[nodeId].second) + ")");
        text.setCharacterSize(14);
        text.setFillColor(Colors::TextColor);
        text.setPosition(500, 150); // Position for displaying node information
        window.draw(text);
    }
}

void Graph::drawEdgeInformation(sf::RenderWindow& window, int fromId, int toId, float weight) {
    // Method to draw information about an edge (used in visualization when an edge is selected)
    if (static_cast<size_t>(fromId) < nodeCoordinates.size() && static_cast<size_t>(toId) < nodeCoordinates.size() && fromId != -1) {
        // Draw information about the edge (e.g., weight, etc.)
        // This is just a placeholder implementation and can be expanded to show more details
        sf::Font font;
        if (!font.loadFromFile("Aloevera.ttf")) {
            // Handle error loading font
            return;
        }
        int numEdges = std::count_if(adjacencyList[fromId].begin(), adjacencyList[fromId].end(), [](int weight) { return weight != -1; });
        sf::Text text;
        text.setFont(font);
        if (numEdges != 0) {
            text.setString
                ("Edge Information \nNumber of Edges: " + std::to_string(numEdges) + "\nEdge from Node " + std::to_string(fromId) + " to Node " + std::to_string(toId) + "\nWeight: " + std::to_string(weight));
        } else {
            text.setString
                ("Edge Information \nNumber of Edges: " + std::to_string(numEdges) + "\nNo Edges from Node " + std::to_string(fromId));
        }
        text.setCharacterSize(14);
        text.setFillColor(Colors::TextColor);
        text.setPosition(500, 200); // Position for displaying edge information
        window.draw(text);
    }
}

void Graph::getNextEdge() {
    // Method to change the currently selected edge in the edge information panel to the next edge (if any)
    if (selectedNodeId == -1) {
        return; // No node is currently selected, so we cannot select an edge
    }

    std::cout << "Selected Node ID: " << selectedNodeId << std::endl; // Debugging output to check the currently selected node ID
    std::cout << "Selected Edge To ID: " << selectedEdgeToId << std::endl; // Debugging output to check the currently selected edge destination node ID

    for (size_t i = 1; i <= adjacencyList[selectedNodeId].size(); i++) {
        if (adjacencyList[selectedNodeId][(i + selectedEdgeToId) % adjacencyList[selectedNodeId].size()] != -1) { // Check if an edge exists
            selectedEdgeToId = (i + selectedEdgeToId) % adjacencyList[selectedNodeId].size(); // Update the selected edge destination node ID to the next edge
            return;
        }
    }
    selectedEdgeToId = -1; // If no edges are found, reset the selected edge destination node ID
}