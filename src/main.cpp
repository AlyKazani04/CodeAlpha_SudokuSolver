#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "interface.hpp"
#include "logic.hpp"


int main(){
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Sudoku Solver");

    window.setFramerateLimit(60);

    Grid grid;
    interface ui;

    int theme = 1; // 0 for dark, 1 for light

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
        }

        { // Render
            window.clear(sf::Color(50, 100, 200));

            grid.draw(window, theme);
            ui.draw(window, theme);
            
            window.display();
        }
    }

    return 0;
}