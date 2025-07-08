#pragma once

#include <SFML/Graphics.hpp>

class Grid{
    public:
        Grid() = default;
        
        void draw(sf::RenderWindow& window);

        ~Grid() = default;
};
