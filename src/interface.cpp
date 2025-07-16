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

    if(!m_newTexture.loadFromFile("../resources/newButton.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_newTexture.setSmooth(false);

    if(!m_modeTextureL.loadFromFile("../resources/lightMode.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_modeTextureL.setSmooth(false);

    if(!m_modeTextureD.loadFromFile("../resources/darkMode.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_modeTextureD.setSmooth(false);

    if(!m_checkTexture.loadFromFile("../resources/checkButton.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_checkTexture.setSmooth(false);
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

bool interface::isDarkPressed(sf::RenderWindow& window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if(m_darkBounds.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_modeChangeCooldown.getElapsedTime().asSeconds() > 0.5f)
    {
        m_isDark = !m_isDark;
        m_modeChangeCooldown.restart();
        return true;
    }
    
    return false;
}

bool interface::isCheckPressed(sf::RenderWindow& window, const interface& ui)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if(ui.m_checkBounds.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        return true;
    }
    
    return false;
}

bool interface::isDark()
{
    return m_isDark;
}

void interface::draw(sf::RenderWindow& window)
{
    sf::Text Title(m_font, "Sudoku Solver", 40);

    Title.setPosition({window.getView().getSize().x / 2 - Title.getLocalBounds().size.x / 2, 40});
    Title.setFillColor((m_isDark) ? sf::Color::White : sf::Color::Black);

    sf::Sprite resetSprite(m_resetTexture);
    sf::Sprite solveSprite(m_solveTexture);
    sf::Sprite newSprite(m_newTexture);
    sf::Sprite checkSprite(m_checkTexture);

    sf::Texture modeTexture;

    if(m_isDark == true)
    {
        modeTexture = m_modeTextureL;
    }
    else
    {
        modeTexture = m_modeTextureD;
    }

    sf::Sprite modeSprite(modeTexture);

    resetSprite.setScale({2,2});
    solveSprite.setScale({2,2});
    newSprite.setScale({2,2});
    modeSprite.setScale({1,1});
    checkSprite.setScale({2,2});

    sf::FloatRect resetbounds = resetSprite.getLocalBounds();
    resetSprite.setOrigin({resetbounds.size.x / 2, resetbounds.size.y / 2});
    
    sf::FloatRect solvebounds = solveSprite.getLocalBounds();
    solveSprite.setOrigin({solvebounds.size.x / 2, solvebounds.size.y / 2});

    sf::FloatRect newbounds = newSprite.getLocalBounds();
    newSprite.setOrigin({newbounds.size.x / 2, newbounds.size.y / 2});

    sf::FloatRect modebounds = modeSprite.getLocalBounds();
    modeSprite.setOrigin({modebounds.size.x / 2, modebounds.size.y / 2});

    sf::FloatRect checkbounds = checkSprite.getLocalBounds();
    checkSprite.setOrigin({checkbounds.size.x / 2, checkbounds.size.y / 2});

    newSprite.setPosition(sf::Vector2f(1 * window.getView().getSize().x / 5, window.getView().getSize().y - 50));

    checkSprite.setPosition(sf::Vector2f(2 * window.getView().getSize().x / 5, window.getView(). getSize().y - 50));
    
    resetSprite.setPosition(sf::Vector2f(3 * window.getView().getSize().x / 5 , window.getView().getSize().y - 50));
    
    solveSprite.setPosition(sf::Vector2f(4 * window.getView().getSize().x / 5, window.getView().getSize().y - 50));

    modeSprite.setPosition(sf::Vector2f(window.getView().getSize().x - modeSprite.getLocalBounds().size.x / 2, modeSprite.getLocalBounds().size.y));


    m_newBounds = newSprite.getGlobalBounds();
    m_resetBounds = resetSprite.getGlobalBounds();
    m_solveBounds = solveSprite.getGlobalBounds();
    m_darkBounds = modeSprite.getGlobalBounds();
    m_checkBounds = checkSprite.getGlobalBounds();

    window.draw(Title);
    window.draw(resetSprite);
    window.draw(solveSprite);
    window.draw(newSprite);
    window.draw(modeSprite);
    window.draw(checkSprite);
}
