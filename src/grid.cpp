#include "grid.hpp"

Grid::Grid()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            m_cellRects[i][j].setSize({60, 60});
            m_cellRects[i][j].setPosition(sf::Vector2f(130 + i * 60, 130 + j * 60));
            m_cellRects[i][j].setFillColor(sf::Color::White);
        }
    }

    for(int i = 0; i < 10; i++)
    {
        m_gridLinesX[i].setFillColor(sf::Color::Black);

        m_gridLinesY[i].setFillColor(sf::Color::Black);

        m_gridLinesX[i].setPosition(sf::Vector2f(130, 130 + i * 60));
        m_gridLinesY[i].setPosition(sf::Vector2f(130 + i * 60, 130));

        if(i % 3 == 0)
        {
            m_gridLinesX[i].setSize({540, 4});
            m_gridLinesY[i].setSize({4, 540});
        } else
        {
            m_gridLinesX[i].setSize({540, 2});
            m_gridLinesY[i].setSize({2, 540});
        }

    }
}

void Grid::update(sf::RenderWindow& window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    sf::Rect<float> tempRect;

    for(auto& cells : m_cellRects)
    {
        for(auto& cell : cells)
        {
            tempRect = cell.getGlobalBounds();

            if(tempRect.contains(mousePos))
            {
                cell.setFillColor(sf::Color(200, 200, 200));
            } 
            else
            {
                cell.setFillColor(sf::Color::White);
            }
        }
    }
}

void Grid::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            window.draw(m_cellRects[i][j]);
        }
    }    

    for(int i = 0; i < 10; i++)
    {
        window.draw(m_gridLinesX[i]);
        window.draw(m_gridLinesY[i]);
    }
}