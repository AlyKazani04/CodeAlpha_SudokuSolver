#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "interface.hpp"
#include "logic.hpp"


int main(){
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Sudoku Solver");

    window.setFramerateLimit(60);

    Grid grid;
    interface ui;

    int theme = 1;

    sf::Color bgColor[2] = { sf::Color(30, 30, 30), sf::Color(50, 100, 200)};

    srand(time(0));

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent()) // event handling
        {
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        { // Update
            grid.update(window, ui);

            ui.isDarkPressed(window);

            if(ui.isDark())
            {
                theme = 0;
            }
            else
            {
                theme = 1;
            }
        }

        { // Render
            window.clear(bgColor[theme]);

            grid.draw(window);
            ui.draw(window);
            
            window.display();
        }
    }

    return 0;
}