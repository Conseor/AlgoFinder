#include "Visualization.hpp"
#include <iostream>

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
    sf::CircleShape nodeShape(10); // Example node shape
    // nodeShape.setFillColor(nodeColor);
    // nodeShape.setPosition(100, 200); // Example node position

    graph.draw(window); // Draw the graph using its own draw method (which should use the nodeColor and edgeColor)
    // window.draw(nodeShape);
    
}

void Visualization::update() {
    // Update visualization state (e.g., for animations)
    // This could involve updating the positions of nodes, changing colors, etc.
}

int Visualization::handleEvent(const sf::Event& event) {
    // Handle events specific to visualization (e.g., mouse clicks)
    
    int relativeX;
    int relativeY;

    switch (event.type){
        case sf::Event::MouseButtonPressed:
            relativeX = (event.mouseButton.x - graphSpace.getPosition().x) / pixelWidth;
            relativeY = (event.mouseButton.y - graphSpace.getPosition().y) / pixelWidth;
            if (event.mouseButton.button == sf::Mouse::Left) {

                std::cout << "Mouse clicked in visualization state" << std::endl;
                if (relativeX > 0 && relativeX < 20 - 1 && relativeY > 0 && relativeY < 20 - 1) { // Assuming graph space is 400x400 and pixelWidth is 20
                    
                    // Either Make a new node or show node properties if a node already exists at this location
                    
                    std::cout << "Mouse clicked within Graph Space" << std::endl;
                    std::cout << "Mouse position relative to Graph Space: (" << relativeX << ", " << relativeY << ")" << std::endl;

                    graph.addNode(relativeX, relativeY); // Example of adding a node at the clicked position (relative to graph space)

                } else {
                    std::cout << "Mouse clicked outside of Graph Space" << std::endl;
                }
            } else if (event.mouseButton.button == sf::Mouse::Right) {
                std::cout << "Right mouse button clicked in visualization state" << std::endl;
                int nodeId = graph.nodeAtCoordinates(relativeX, relativeY); // Example of checking if a node exists at the clicked position (relative to graph space)
                if (nodeId != -1) {
                    std::cout << "Node found at coordinates (" << relativeX << ", " << relativeY << ")" << std::endl;
                    graph.removeNode(nodeId);
                } else {
                    std::cout << "No node found at coordinates (" << relativeX << ", " << relativeY << ")" << std::endl;
                }
            }
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                // Handle Escape key press (e.g., to return to menu)
                std::cout << "Escape key pressed in visualization state" << std::endl;
                return 0;
            } else if (event.key.code == sf::Keyboard::R) {
                // Handle R key press to reset the graph
                std::cout << "R key pressed in visualization state - resetting graph" << std::endl;
                graph.reset();
            }
            break;
        default:
            break;
    }
    return 1; // Return 1 to indicate that we are still in visualization state, or 0 to indicate that we should return to menu
}