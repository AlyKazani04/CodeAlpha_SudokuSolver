#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "interface.hpp"
#include "logic.hpp"

class Grid : public Generator, public Solver
{
    public:
        Grid();
        
        void update(sf::RenderWindow& window, interface& ui);

        void draw(sf::RenderWindow& window);

        ~Grid() = default;

        friend bool interface::isNewPressed(sf::RenderWindow& window, const interface& ui);
        friend bool interface::isResetPressed(sf::RenderWindow& window, const interface& ui);
        friend bool interface::isSolvePressed(sf::RenderWindow& window, const interface& ui);
    private:
        sf::RectangleShape m_cellRects[9][9];
        sf::RectangleShape m_gridLinesX[10];
        sf::RectangleShape m_gridLinesY[10];

        std::vector<std::vector<int>> m_map;

        std::vector<std::vector<int>> m_resetMap;

        sf::Font m_font;

        std::string toString(int num);

        void resetMap(std::vector<std::vector<int>>& map);
};