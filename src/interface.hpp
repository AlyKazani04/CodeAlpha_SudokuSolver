#pragma once 

#include <SFML/Graphics.hpp>

class interface
{
    public:

        interface();

        void draw(sf::RenderWindow& window);

        bool isNewPressed(sf::RenderWindow& window, const interface& ui);
        bool isResetPressed(sf::RenderWindow& window, const interface& ui);
        bool isSolvePressed(sf::RenderWindow& window, const interface& ui);
        bool isDarkPressed(sf::RenderWindow& window);
        bool isCheckPressed(sf::RenderWindow& window, const interface& ui);
        
        bool isDark();
        
        ~interface() = default;
    private:
        sf::Font m_font;
        
        sf::Texture m_newTexture;
        sf::Texture m_solveTexture;
        sf::Texture m_resetTexture;
        sf::Texture m_modeTextureL;
        sf::Texture m_modeTextureD;
        sf::Texture m_checkTexture;
        
        sf::Rect<float> m_newBounds;
        sf::Rect<float> m_solveBounds;
        sf::Rect<float> m_resetBounds;
        sf::Rect<float> m_darkBounds;
        sf::Rect<float> m_checkBounds;
        
        sf::Clock m_modeChangeCooldown;
        
        bool m_isDark = false;

};
