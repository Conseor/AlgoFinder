#pragma once
#include <SFML/Graphics.hpp>
#include "Graph.hpp"
class Visualization {
public:
    Visualization(sf::Color nodeColor, sf::Color edgeColor, sf::Color visitedNodeColor, sf::Color graphSpaceColor);
    void draw(sf::RenderWindow& window);
    void update(); // Update visualization state (e.g., for animations)
    int handleEvent(const sf::Event& event); // Handle events specific to visualization (e.g., mouse clicks)
private:
    sf::Color nodeColor;
    sf::Color edgeColor;
    sf::Color visitedNodeColor;
    sf::Color graphSpaceColor;
    sf::RectangleShape graphSpace; // Shape for drawing Graph Area
    int pixelWidth = 20; // Pixel width for each unit in graph space
    Graph graph; // Instance of the Graph class
    // Additional members for storing graph data, visited nodes, etc.
};