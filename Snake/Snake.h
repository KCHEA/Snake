#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Snake {
private:
	int length;
	int radius;
public:
	Snake();
	std::vector<sf::CircleShape>  draw();
};