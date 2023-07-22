#pragma once
#include <SFML/Graphics.hpp>

class Food {
private:
	float radius;
	sf::Color color;
public:
	Food();
	sf::CircleShape draw();
};