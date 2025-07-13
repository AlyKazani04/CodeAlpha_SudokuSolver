#pragma once 

#include <SFML/Graphics.hpp>

class interface
{
    public:

        interface();

        void draw(sf::RenderWindow& window, int& theme);

        bool isNewPressed(sf::RenderWindow& window, const interface& ui);
        bool isResetPressed(sf::RenderWindow& window, const interface& ui);
        bool isSolvePressed(sf::RenderWindow& window, const interface& ui);
        bool isModeChangePressed(sf::RenderWindow& window, const interface& ui);

        ~interface() = default;
    private:
    sf::Font m_font;

    sf::Texture m_newTexture;
    sf::Texture m_solveTexture;
    sf::Texture m_resetTexture;
    sf::Texture m_modeTextureL;
    sf::Texture m_modeTextureD;

    sf::Rect<float> m_newBounds;
    sf::Rect<float> m_solveBounds;
    sf::Rect<float> m_resetBounds;
    sf::Rect<float> m_modeBounds;

    sf::Clock modeChangeCooldown;

    bool isDark = false;
};
