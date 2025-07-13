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

        void draw(sf::RenderWindow& window, const int theme);

        ~Grid() = default;

        friend bool interface::isNewPressed(sf::RenderWindow& window, const interface& ui);
        friend bool interface::isResetPressed(sf::RenderWindow& window, const interface& ui);
        friend bool interface::isSolvePressed(sf::RenderWindow& window, const interface& ui);
        friend bool interface::isModeChangePressed(sf::RenderWindow& window, const interface& ui);
    private:
        sf::RectangleShape m_cellRects[9][9];
        sf::RectangleShape m_gridLinesX[10];
        sf::RectangleShape m_gridLinesY[10];

        const sf::Color m_lineColor[2] = {sf::Color::White, sf::Color::Black};
        const sf::Color m_cellColor[2] = {sf::Color(45, 45, 45), sf::Color::White};

        std::vector<std::vector<int>> m_map;

        std::vector<std::vector<int>> m_resetMap;

        sf::Font m_font;

        std::string toString(int num);

        void resetMap(std::vector<std::vector<int>>& map);
};