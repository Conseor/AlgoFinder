#pragma once
#include <SFML/Graphics.hpp>

sf::Color hexToColor(const std::string& hex);

/*
    #0D3B66
    #FAF0CA
    #F4D35E
    #EE964B
    #F95738
*/

namespace Colors {
    // Define some colors for use in the visualization
    const sf::Color NodeColor = hexToColor("#F95738"); // Color for nodes
    const sf::Color EdgeColor = hexToColor("#EE964B"); // Color for edges
    const sf::Color SelectedNodeColor = hexToColor("#F4D35E"); // Color for selected nodes
    const sf::Color SelectedEdgeColor = hexToColor("#F4D35E"); // Color for selected edges
    const sf::Color MenuBackgroundColor = hexToColor("#0D3B66"); // Color for menu background
    const sf::Color VisualizationBackgroundColor = hexToColor("#0D3B66"); // Dark background color for better contrast
    const sf::Color GraphSpaceColor = hexToColor("#FAF0CA"); // Light color for graph space
    const sf::Color VisitedNodeColor = sf::Color(255, 165, 0); // Orange color for visited nodes during algorithm visualization
    const sf::Color TextColor = hexToColor("#FAF0CA"); // Color for text in the visualization
}




