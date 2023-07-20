#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
//we will create a 20x20 grid for the game so each cell is 1000/20 = 50 pixels square;

class Grid {
private:
	int cellSize;
	int numRows;
	int numColumns;
	sf::Color tileColor1;
	sf::Color tileColor2;
public:
	Grid();
	std::vector<sf::RectangleShape> draw();
};