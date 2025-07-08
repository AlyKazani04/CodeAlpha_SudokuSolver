#include "grid.hpp"

void Grid::draw(sf::RenderWindow& window)
{
    sf::RectangleShape gridBG({540, 540});
    gridBG.setFillColor(sf::Color::White);

    gridBG.setPosition(sf::Vector2f(130,130));

    window.draw(gridBG);

    sf::RectangleShape lineX({540, 2});
    lineX.setFillColor(sf::Color::Black);

    sf::RectangleShape lineY({2, 540});
    lineY.setFillColor(sf::Color::Black);   
    
    for(int i = 0; i <= 9; i++)
    {
        lineX.setPosition(sf::Vector2f(130, 130 + i * 60));
        lineY.setPosition(sf::Vector2f(130 + i * 60, 130));

        window.draw(lineX);
        window.draw(lineY);
    }
}