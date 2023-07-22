#include "Food.h"

Food::Food()
	:radius{ 25 }, color{ sf::Color::Red } {}

sf::CircleShape Food::draw() {
	sf::CircleShape food;
	food.setRadius(radius);
	food.setFillColor(color);
	food.setPosition(500,500);

	return food;
}