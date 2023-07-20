#include <SFML/Graphics.hpp>
#include "Grid.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML window");

	Grid grid = Grid();
	

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (const auto& cells : grid.draw()) {
			window.draw(cells);
		}

		window.display();
	}

	return 0;
}