#include "Grid.h"

Grid::Grid()
	:cellSize{ 50 }, numRows{ 20 }, numColumns{ 20 }, tileColor1{ sf::Color(61,145,64,255)}, tileColor2{sf::Color(123,182,97)} {}

std::vector<sf::RectangleShape> Grid::draw() {
	std::vector<sf::RectangleShape> grid;
	for (int rows = 0; rows < numRows; rows++) {
		for (int columns = 0; columns < numColumns; columns++) {
			sf::RectangleShape rectangle(sf::Vector2f(cellSize, cellSize));

			//this if statement alternate the two file color between tileColor1 and tileColor2
			if (rows % 2 == 0) {
				if (columns % 2 == 0)
					rectangle.setFillColor(tileColor1);
				else
					rectangle.setFillColor(tileColor2);
			}
			else {
				if (columns % 2 == 0)
					rectangle.setFillColor(tileColor2);
				else
					rectangle.setFillColor(tileColor1);
			}
				

			rectangle.setPosition(columns * cellSize, rows * cellSize);
			grid.push_back(rectangle);
		}
	}
	return grid;
}