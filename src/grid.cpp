#include "grid.hpp"

Grid::Grid()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            m_cellRects[i][j].setSize({60, 60});
            m_cellRects[i][j].setPosition(sf::Vector2f(130 + j * 60, 130 + i * 60));
            // m_cellColors[i][j] = sf::Color::White;
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

    if(!m_font.openFromFile("../resources/RobotoCondensedRegular.ttf"))
    {
        throw std::runtime_error("Failed to load font!");
    }
    m_font.setSmooth(false);

    m_map.resize(9);

    for(auto& row : m_map)
    {
        row.resize(9);

        for(int i = 0; i < 9; i++)
        {
            row[i] = 0;
        }
    }
}

void Grid::update(sf::RenderWindow& window, interface& ui)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    sf::Rect<float> tempRect;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            tempRect = m_cellRects[i][j].getGlobalBounds();

            sf::Vector2f curMousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            if(tempRect.contains(mousePos))
            {
                m_cellColors[i][j] = sf::Color(200, 200, 200);

                const auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Text).value();
                window.setMouseCursor(cursor);
            } 
            else
            {
                m_cellColors[i][j] = sf::Color::White;
            }
        }
    }

    sf::Rect<float> gridBounds = {{130,130}, {540,540}};

    if(!gridBounds.contains(mousePos))
    {
        const auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
        window.setMouseCursor(cursor);
    }

    if(ui.isNewPressed(window, ui))
    {
        generateSudokuPuzzle(m_map, m_solutionMap, 45); // medium difficulty
        m_resetMap = m_map;

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                m_editableCell[i][j] = (m_map[i][j] == 0);
                m_cellColors[i][j] = sf::Color::White;
            }
        }

    }

    if(ui.isResetPressed(window, ui))
    {
        resetMap(m_map);
    }

    if(ui.isSolvePressed(window, ui))
    {
        solve(m_map, 0, 0);
        m_solutionMap = m_map;
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(m_cellRects[i][j].getGlobalBounds().contains(mousePos))
                {
                    m_selectedCell = {i, j};
                }
            }
        }
    }

    if(m_selectedCell.x != -1 && m_selectedCell.y != -1)
    {
        for(int k = (int)sf::Keyboard::Key::Num1; k <= (int)sf::Keyboard::Key::Num9; k++)
        {
            if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)) && m_editableCell[m_selectedCell.x][m_selectedCell.y])
            {
                m_map[m_selectedCell.x][m_selectedCell.y] = k - (int)sf::Keyboard::Key::Num0;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num0) && m_editableCell[m_selectedCell.x][m_selectedCell.y])
        {
            m_map[m_selectedCell.x][m_selectedCell.y] = 0;
        }
    }

    if(ui.isCheckPressed(window, ui))
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(m_editableCell[i][j])
                {
                    if(m_map[i][j] == 0)
                    {
                        m_cellColors[i][j] = sf::Color::White;
                    }
                    else if(m_map[i][j] == m_solutionMap[i][j])
                    {
                        m_cellColors[i][j] = sf::Color(144, 238, 144); // light green
                    }
                    else
                    {
                        m_cellColors[i][j] = sf::Color(255, 182, 193); // light red
                    }
                }
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
            m_cellRects[i][j].setFillColor(m_cellColors[i][j]);

            if(m_selectedCell.x == i && m_selectedCell.y == j)
            {
                m_cellRects[i][j].setFillColor(sf::Color(180, 220, 255));
            }

            window.draw(m_cellRects[i][j]);

            sf::Rect<float> cellBounds = m_cellRects[i][j].getGlobalBounds();

            sf::Vector2f cellCenter({cellBounds.position.x + cellBounds.size.x / 2, cellBounds.position.y + cellBounds.size.y / 2});

            sf::Text value(m_font,toString(m_map[i][j]), 20);
            value.setFillColor(sf::Color::Black);

            sf::Rect<float> textBounds = value.getLocalBounds();

            value.setOrigin({textBounds.position.x + textBounds.size.x / 2, textBounds.position.y + textBounds.size.y / 2});

            value.setPosition(cellCenter);

            window.draw(value);
        }
    }

    for(int i = 0; i < 10; i++)
    {
        window.draw(m_gridLinesX[i]);
        window.draw(m_gridLinesY[i]);
    }
}

std::string Grid::toString(int num)
{
    if(num == 0)
    {
        return "";
    }

    return std::to_string(num);
}

void Grid::resetMap(std::vector<std::vector<int>>& map)
{
    m_map = m_resetMap; 

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            m_editableCell[i][j] = (m_map[i][j] == 0);
            m_cellColors[i][j] = sf::Color::White;
        }
    }
}