#include "Colors.hpp"

sf::Color hexToColor(const std::string& hex) {
    if (hex.size() != 7 || hex[0] != '#') {
        throw std::invalid_argument("Invalid hex color format");
    }
    unsigned int r = std::stoul(hex.substr(1, 2), nullptr, 16);
    unsigned int g = std::stoul(hex.substr(3, 2), nullptr, 16);
    unsigned int b = std::stoul(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}