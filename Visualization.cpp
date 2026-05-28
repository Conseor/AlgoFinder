#include "Visualization.hpp"

Visualization::Visualization(sf::Color nodeColor, sf::Color edgeColor, sf::Color visitedNodeColor, sf::Color graphSpaceColor)
    : nodeColor(nodeColor), edgeColor(edgeColor), visitedNodeColor(visitedNodeColor), graphSpaceColor(graphSpaceColor) {
    // Initialize graph data, visited nodes, etc.

    // Set up graph space shape
    graphSpace.setSize(sf::Vector2f(400, 400)); // Example size
    graphSpace.setFillColor(graphSpaceColor);
    graphSpace.setPosition(50, 150); // Example position
}

void Visualization::draw(sf::RenderWindow& window) {
    // Draw nodes, edges, and visited nodes here using SFML shapes and colors

    // Example: Draw graph space
    window.draw(graphSpace);
    
}

void Visualization::update() {
    // Update visualization state (e.g., for animations)
    // This could involve updating the positions of nodes, changing colors, etc.
}

