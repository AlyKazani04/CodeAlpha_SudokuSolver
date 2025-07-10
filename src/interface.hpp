#pragma once 

#include <SFML/Graphics.hpp>

class interface
{
    public:

        interface();

        void draw(sf::RenderWindow& window);

        ~interface() = default;
    private:
    sf::Font m_font;
    sf::Texture m_resetTexture;
    sf::Texture m_solveTexture;
};
