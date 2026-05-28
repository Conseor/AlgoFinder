#pragma once

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(sf::Color textColor = sf::Color::White);
    void draw(sf::RenderWindow& window);
    int handleEvent(const sf::Event& event);
    
private:
    sf::Color textColor;
    sf::Font font;
    sf::Text title;
    sf::Text option1;
    sf::Text option2;
    sf::Text option3;
};