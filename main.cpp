// This is going to be the main file for the project.

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "Visualization.hpp"

sf::Color hexToColor(const std::string& hex) {
    if (hex.size() != 7 || hex[0] != '#') {
        throw std::invalid_argument("Invalid hex color format");
    }
    unsigned int r = std::stoul(hex.substr(1, 2), nullptr, 16);
    unsigned int g = std::stoul(hex.substr(3, 2), nullptr, 16);
    unsigned int b = std::stoul(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}

int main () {
    
    // List of Hex Colors for Elements in Project
    /* Color Pallet
    - Window Background: #FFADAD
    - Node Color: #FFD6A5
    - Edge Color: #FDFFB6
    - Visited Node Color: #CAFFBF
    - Color: #9BF6FF
    - Color: #A0C4FF
    - Color: #BDB2FF
    - Color: #FFC6FF
    - Color: #FFFFFC 

    COLORS FOR MENU
    #0D3B66
    #FAF0CA
    #F4D35E
    #EE964B
    #F95738
    */
    
    sf::Color menuBackgroundColor = hexToColor("#0D3B66");
    sf::Color visualizationBackgroundColor = hexToColor("#FAF0CA");
    sf::Color textColor = hexToColor("#FAF0CA");
    
    enum state {MENU, VISUALIZATION};
    state currentState = MENU;
    int selectedOption = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithm Visualizer");

    Menu menu = Menu(textColor); // Example of using a hex color for menu text
    Visualization visualization(hexToColor("#FFD6A5"), hexToColor("#FDFFB6"), hexToColor("#CAFFBF"), hexToColor("#0D3B66"));
    

    // Main Render Loop
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (currentState == MENU) {
                selectedOption = menu.handleEvent(event);
            } 
            else if (currentState == VISUALIZATION) {
                // Handle visualization events here
                selectedOption = visualization.handleEvent(event);
                
            }

            if (selectedOption != 0) {
                currentState = VISUALIZATION;
                // Initialize visualization based on selectedOption
            } else {
                currentState = MENU;
            }
        }

        

        // Draw stuff here

        switch(currentState) {
            case MENU:
                window.clear(menuBackgroundColor);
                menu.draw(window);
                break;
            case VISUALIZATION:
                // Draw visualization here
                window.clear(visualizationBackgroundColor);
                visualization.draw(window);
                break;
        }

        window.display();

    }

    return 0;
}
