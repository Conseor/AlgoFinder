#include "Menu.hpp"
#include <iostream>

Menu::Menu(sf::Color textColor) : textColor(textColor) {
    // Load font
    if (!font.loadFromFile("Aloevera.ttf")) {
        // Handle error
    }

    // Set up title
    title.setFont(font);
    title.setString("Algorithm Visualizer");
    title.setCharacterSize(48);
    title.setFillColor(textColor);
    title.setPosition(200, 50);

    // Set up options
    option1.setFont(font);
    option1.setString("1. Dijkstra's Algorithm");
    option1.setCharacterSize(24);
    option1.setFillColor(textColor);
    option1.setPosition(250, 150);

    option2.setFont(font);
    option2.setString("2. A* Search");
    option2.setCharacterSize(24);
    option2.setFillColor(textColor);
    option2.setPosition(250, 200);

    option3.setFont(font);
    option3.setString("3. Bellman-Ford Algorithm");
    option3.setCharacterSize(24);
    option3.setFillColor(textColor);
    option3.setPosition(250, 250);
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(title);
    window.draw(option1);
    window.draw(option2);
    window.draw(option3);
}

int Menu::handleEvent(const sf::Event& event) {
    // Handle menu events (e.g., key presses to select options)
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Num1) {
            // Handle option 1
            std::cout << "Option 1 selected: Dijkstra's Algorithm" << std::endl;
            return 1;
        } else if (event.key.code == sf::Keyboard::Num2) {
            // Handle option 2
            std::cout << "Option 2 selected: A* Search" << std::endl;
            return 2;
        } else if (event.key.code == sf::Keyboard::Num3) {
            // Handle option 3
            std::cout << "Option 3 selected: Bellman-Ford Algorithm" << std::endl;
            return 3;
        }
    }
    return 0; // No option selected
}