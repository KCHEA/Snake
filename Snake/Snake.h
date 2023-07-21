#pragma once
#include <vector>
#include <SFML/Graphics.hpp>


class Snake {
private:
	float length;
	float radius;
	sf::Color snakeColor;
	std::vector<sf::CircleShape>  draw();
	std::vector<sf::CircleShape>  snakeBody;
public:
	Snake();
	std::vector<sf::CircleShape> getBody();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	bool isHitWall();
	void grow();
};