#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Snake.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Snake");
	window.setFramerateLimit(2);
	
	Grid grid = Grid();
	Snake snake = Snake();
	

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (const auto& cells : grid.draw()) { //this loop draw the grid onto the window
			window.draw(cells);
		}

		for (const auto& segment : snake.getBody()) { //this loop draw the snake onto the window
			window.draw(segment);
		}
		if (!snake.isHitWall()) {
			snake.moveDown();
			
		}
		
		
		
		window.display();
	}

	return 0;
}