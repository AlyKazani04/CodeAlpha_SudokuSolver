#include "interface.hpp"

interface::interface()
{
    if(!m_font.openFromFile("../resources/RobotoCondensedRegular.ttf"))
    {
        throw std::runtime_error("Failed to load font!");
    }
    m_font.setSmooth(false);

    if(!m_resetTexture.loadFromFile("../resources/resetButton.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_resetTexture.setSmooth(false);

    if(!m_solveTexture.loadFromFile("../resources/solveButton.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_solveTexture.setSmooth(false);
}

void interface::draw(sf::RenderWindow& window)
{
    sf::Text Title(m_font, "Sudoku Solver", 40);

    Title.setPosition({window.getView().getSize().x / 2 - Title.getLocalBounds().size.x / 2, 40});
    Title.setFillColor(sf::Color::Black);

    sf::Sprite resetSprite(m_resetTexture);
    sf::Sprite solveSprite(m_solveTexture);

    resetSprite.setScale({2,2});
    solveSprite.setScale({2,2});

    sf::FloatRect resetbounds = resetSprite.getLocalBounds();
    resetSprite.setOrigin({resetbounds.size.x / 2, resetbounds.size.y / 2});
    
    sf::FloatRect solvebounds = solveSprite.getLocalBounds();
    solveSprite.setOrigin({solvebounds.size.x / 2, solvebounds.size.y / 2});

    resetSprite.setPosition(sf::Vector2f(window.getView().getSize().x / 2 , window.getView().getSize().y - 50));

    solveSprite.setPosition(sf::Vector2f(window.getView().getSize().x / 4, window.getView().getSize().y - 50));


    window.draw(Title);
    window.draw(resetSprite);
    window.draw(solveSprite);
}
