#pragma once

#include <SFML/Graphics.hpp>
#include "logic.hpp"

class Grid
{
    public:
        Grid();
        
        void update(sf::RenderWindow& window);

        void draw(sf::RenderWindow& window);

        ~Grid() = default;
    private:
        sf::RectangleShape m_cellRects[9][9];
        sf::RectangleShape m_gridLinesX[10];
        sf::RectangleShape m_gridLinesY[10];
        

        std::vector<std::vector<int>> m_map;

        friend bool Solver::isCellValid(const std::vector<std::vector<int>>& map, int row, int col, int cellVal);

        friend bool Solver::solve(std::vector<std::vector<int>>& map, int row, int col);
};