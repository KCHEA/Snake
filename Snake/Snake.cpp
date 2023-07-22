#include "Snake.h"

Snake::Snake()
	:length{ 3 }, radius{ 25 }, snakeColor{ sf::Color(150,113,23,255) }, snakeBody {draw()} {}

std::vector<sf::CircleShape>  Snake::draw() {
	std::vector<sf::CircleShape> body;
	int i = 0;
	while (i < length) {
		sf::CircleShape segment;
		segment.setFillColor(snakeColor);
		segment.setRadius(radius);

		segment.setPosition(2 * radius * i, 200);

		body.push_back(segment);

		i++;
	}
	return body;
}

std::vector<sf::CircleShape> Snake::getBody() {
	return snakeBody;
}

bool Snake::isHitWall() {
	sf::CircleShape head = snakeBody.back();
	sf::Vector2f headPosition = head.getPosition();

	if (headPosition.x < 50 || headPosition.x > 700 || headPosition.y < 50 || headPosition.y > 700)
		return true;
	else
		return false;
	
}void Snake::moveRight() { //this move the snake by erasing the tail and adding the head to body
	snakeBody.erase(snakeBody.begin());
	sf::CircleShape newHead;
	newHead.setRadius(radius);
	newHead.setFillColor(snakeColor);

	sf::CircleShape lastHead = snakeBody.back();
	sf::Vector2f position = lastHead.getPosition();

	newHead.setPosition(2 * radius + position.x, position.y);

	snakeBody.push_back(newHead);
}

void Snake::moveLeft() {
	snakeBody.erase(snakeBody.begin());
	sf::CircleShape newHead;
	newHead.setRadius(radius);
	newHead.setFillColor(snakeColor);

	sf::CircleShape lastHead = snakeBody.back();
	sf::Vector2f position = lastHead.getPosition();

	newHead.setPosition(-2*radius + position.x, position.y);

	snakeBody.push_back(newHead);
}


void Snake::moveDown() {
	snakeBody.erase(snakeBody.begin());
	sf::CircleShape newHead;
	newHead.setRadius(radius);
	newHead.setFillColor(snakeColor);

	sf::CircleShape lastHead = snakeBody.back();
	sf::Vector2f position = lastHead.getPosition();

	newHead.setPosition(position.x, 2*radius + position.y);

	snakeBody.push_back(newHead);
}

void Snake::moveUp() {
	snakeBody.erase(snakeBody.begin());
	sf::CircleShape newHead;
	newHead.setRadius(radius);
	newHead.setFillColor(snakeColor);

	sf::CircleShape lastHead = snakeBody.back();
	sf::Vector2f position = lastHead.getPosition();

	newHead.setPosition(position.x, -2 * radius + position.y);

	snakeBody.push_back(newHead);
}

void Snake::grow() {
	sf::CircleShape newTail;
	newTail.setFillColor(snakeColor);
	newTail.setRadius(radius);

	sf::CircleShape lastTail;
	lastTail = snakeBody.front();
	sf::Vector2f position = lastTail.getPosition();

	newTail.setPosition(-2 * radius + position.x, position.y);

	snakeBody.insert(snakeBody.begin(), newTail);
}