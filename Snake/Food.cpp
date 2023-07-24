#include "Food.h"
#include <random>

Food::Food()
	:radius{ 25 }, color{ sf::Color::Red } {}

sf::CircleShape Food::draw() {
	sf::CircleShape food;
	food.setRadius(radius);
	food.setFillColor(color);
	
	//generate a random coordinate for the food spawn
	std::random_device rd;
	std::mt19937 gen(rd());

	int min_value = 0;
	int max_value = 800;

	std::uniform_int_distribution<int> distribution(min_value, max_value);
	int random_number = distribution(gen);

	food.setPosition(random_number,random_number);

	return food;
}