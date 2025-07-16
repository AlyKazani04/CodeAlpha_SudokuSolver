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
        friend bool interface::isCheckPressed(sf::RenderWindow& window, const interface& ui);

    private:
        sf::RectangleShape m_cellRects[9][9];
        sf::RectangleShape m_gridLinesX[10];
        sf::RectangleShape m_gridLinesY[10];

        const sf::Color m_lineColor[2] = {sf::Color::White, sf::Color::Black};

        sf::Color m_cellColors[9][9];

        std::vector<std::vector<int>> m_map;
        std::vector<std::vector<int>> m_solutionMap; 
        std::vector<std::vector<int>> m_resetMap;

        sf::Vector2i m_selectedCell{-1, -1}; // currently selected cell coords 
        bool m_editableCell[9][9] = {}; // which cells can be edited

        sf::Font m_font;

        std::string toString(int num);

        void resetMap(std::vector<std::vector<int>>& map);
};