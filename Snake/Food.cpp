#include "Food.h"
#include <random>

Food::Food()
	:radius{ 25 }, color{ sf::Color::Red } {}

sf::CircleShape Food::draw(float x, float y) {
	sf::CircleShape food;
	food.setRadius(radius);
	food.setFillColor(color);

	food.setPosition(x,y);

	return food;
}