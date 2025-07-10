#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "interface.hpp"
#include <iostream>

int main(){
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Sudoku Solver");

    std::cout << "Current directory: " << std::filesystem::current_path() << std::endl;

    Grid grid;
    interface ui;

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        { // Update
            grid.update(window);
        }

        { // Render
            window.clear(sf::Color(50, 100, 200));

            grid.draw(window);
            ui.draw(window);
            
            window.display();
        }
    }

    return 0;
}