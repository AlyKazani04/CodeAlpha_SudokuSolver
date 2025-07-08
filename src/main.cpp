#include <SFML/Graphics.hpp>
#include "grid.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Sudoku Solver");

    Grid grid;
    
    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        { // Update

        }

        { // Render
            window.clear(sf::Color(50, 100, 200));

            grid.draw(window);
            
            window.display();
        }
    }

    return 0;
}