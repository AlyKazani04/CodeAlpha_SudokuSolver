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

    if(!m_newTexture.loadFromFile("../resources/NewButton.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_newTexture.setSmooth(false);
}

bool interface::isNewPressed(sf::RenderWindow& window, const interface& ui)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if(ui.m_newBounds.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        return true;
    }
    
    return false;
}

bool interface::isResetPressed(sf::RenderWindow& window, const interface& ui)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if(ui.m_resetBounds.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        return true;
    }
    
    return false;

}

bool interface::isSolvePressed(sf::RenderWindow& window, const interface& ui)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if(ui.m_solveBounds.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        return true;
    }
    
    return false;
}

bool interface::isModeChangePressed(sf::RenderWindow& window, const interface& ui)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if(ui.m_modeBounds.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        return true;
    }

    return false;
}

void interface::draw(sf::RenderWindow& window, int& theme)
{
    sf::Text Title(m_font, "Sudoku Solver", 40);

    Title.setPosition({window.getView().getSize().x / 2 - Title.getLocalBounds().size.x / 2, 40});
    Title.setFillColor(sf::Color::Black);

    sf::Sprite resetSprite(m_resetTexture);
    sf::Sprite solveSprite(m_solveTexture);
    sf::Sprite newSprite(m_newTexture);

    resetSprite.setScale({2,2});
    solveSprite.setScale({2,2});
    newSprite.setScale({2,2});

    sf::FloatRect resetbounds = resetSprite.getLocalBounds();
    resetSprite.setOrigin({resetbounds.size.x / 2, resetbounds.size.y / 2});
    
    sf::FloatRect solvebounds = solveSprite.getLocalBounds();
    solveSprite.setOrigin({solvebounds.size.x / 2, solvebounds.size.y / 2});

    sf::FloatRect newbounds = newSprite.getLocalBounds();
    newSprite.setOrigin({newbounds.size.x / 2, newbounds.size.y / 2});

    resetSprite.setPosition(sf::Vector2f(window.getView().getSize().x / 2 , window.getView().getSize().y - 50));

    solveSprite.setPosition(sf::Vector2f(3 * window.getView().getSize().x / 4, window.getView().getSize().y - 50));

    newSprite.setPosition(sf::Vector2f(window.getView().getSize().x / 4, window.getView().getSize().y - 50));

    m_newBounds = newSprite.getGlobalBounds();
    m_resetBounds = resetSprite.getGlobalBounds();
    m_solveBounds = solveSprite.getGlobalBounds();

    window.draw(Title);
    window.draw(resetSprite);
    window.draw(solveSprite);
    window.draw(newSprite);
}
