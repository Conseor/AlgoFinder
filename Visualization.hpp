#pragma once
#include <SFML/Graphics.hpp>
class Visualization {
public:
    Visualization(sf::Color nodeColor, sf::Color edgeColor, sf::Color visitedNodeColor, sf::Color graphSpaceColor);
    void draw(sf::RenderWindow& window);
    void update(); // Update visualization state (e.g., for animations)
private:
    sf::Color nodeColor;
    sf::Color edgeColor;
    sf::Color visitedNodeColor;
    sf::Color graphSpaceColor;
    sf::RectangleShape graphSpace; // Shape for drawing Graph Area
    // Additional members for storing graph data, visited nodes, etc.
};