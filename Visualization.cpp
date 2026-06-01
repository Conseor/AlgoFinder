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
    if (edgeCreationMode) {
        // Draw edge from selected node to mouse position as feedback for edge creation process
        drawTemporaryEdge(window, graph.getSelectedNodeId(), sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        // This will require tracking the mouse position and the selected node's position
    }
    
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

                if (relativeX > 0 && relativeX < 20 - 1 && relativeY > 0 && relativeY < 20 - 1) { // Assuming graph space is 400x400 and pixelWidth is 20
                    
                    // Either Make a new node or show node properties if a node already exists at this location
                    
                    int nodeId = graph.nodeAtCoordinates(relativeX, relativeY); // Example of checking if a node exists at the clicked position (relative to graph space)
                    if (nodeId == -1 && !edgeCreationMode) {
                        graph.addNode(relativeX, relativeY); // Example of adding a node at the clicked position (relative to graph space)
                    } else if (nodeId != -1 && nodeId != graph.getSelectedNodeId() && !edgeCreationMode) { // Check if a node exists and is not already selected
                        graph.selectNode(nodeId); // Example of selecting the node that was left-clicked (for visualization purposes)
                    } else if (nodeId != -1 && nodeId == graph.getSelectedNodeId() && edgeCreationMode) { // Check if the selected node was left-clicked again while in edge creation mode to cancel edge creation process
                        // cancel edge creation process and deselect
                        edgeCreationMode = false;
                        graph.selectNode(-1); // Deselect the node after canceling edge creation process (for visualization purposes)
                    } else if (nodeId != -1 && nodeId != graph.getSelectedNodeId() && edgeCreationMode) { 
                        // Create an Edge between the currently selected node and the newly clicked node, then deselect
                        graph.addEdge(graph.getSelectedNodeId(), nodeId, 1.0f); // Example of adding an edge between the currently selected node and the newly clicked node with a weight of 1.0 (for demonstration purposes)
                        edgeCreationMode = false; // Exit edge creation mode after creating the edge
                        graph.selectNode(-1); // Deselect the node after creating the edge (for visualization
                    } else if (nodeId != -1 && nodeId == graph.getSelectedNodeId()) { // Check if the selected node was left-clicked again to deselect it
                        // start edge creation process
                        edgeCreationMode = true;

                        // Draw edge from node to mouse position as feedback for edge creation process (if clicked again, cancel edge creation process and deselect)
                        // If another node is left-clicked while a node is already selected, create an edge between the two nodes and deselect
                        // graph.selectNode(-1); // Deselect the node after starting edge creation process (for visualization purposes)
                    }
                } else {
                }
            } else if (event.mouseButton.button == sf::Mouse::Right) {
                int nodeId = graph.nodeAtCoordinates(relativeX, relativeY); // Example of checking if a node exists at the clicked position (relative to graph space)
                if (nodeId != -1 && !edgeCreationMode) {
                    graph.removeNode(nodeId);
                } else {
                    // std::cout << "No node found at coordinates (" << relativeX << ", " << relativeY << ")" << std::endl;
                }
            }
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                // Handle Escape key press (e.g., to return to menu)
                return 0;
            } else if (event.key.code == sf::Keyboard::R) {
                // Handle R key press to reset the graph
                graph.reset();
            }
            break;
        default:
            break;
    }
    return 1; // Return 1 to indicate that we are still in visualization state, or 0 to indicate that we should return to menu
}

void Visualization::drawTemporaryEdge(sf::RenderWindow& window, int fromNodeId, int mouseX, int mouseY) {
    // Method to draw a temporary edge from a selected node to the current mouse position (used during edge creation process)
    // This will require tracking the mouse position and the selected node's position
    // Example implementation (this should be called in the draw method when edgeCreationMode is true):
    if (edgeCreationMode) {
        // Get the coordinates of the selected node
        int selectedNodeId = graph.getSelectedNodeId();
        if (selectedNodeId != -1) {
            // Draw a line from the selected node to the current mouse position
            std::pair<int, int> nodeCoordinates = graph.getNodeCoordinates(selectedNodeId);
            sf::Vertex line[] =
            { 
                sf::Vertex(sf::Vector2f(nodeCoordinates.first * 20 + 55, nodeCoordinates.second * 20 + 155), sf::Color::Blue),
                sf::Vertex(sf::Vector2f(mouseX, mouseY), sf::Color::Blue)
            };
        window.draw(line, 2, sf::Lines);
        }
    }
}