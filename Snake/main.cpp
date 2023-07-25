#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Snake.h"
#include "Food.h"
#include <random>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Snake");
	window.setFramerateLimit(3);
	
	Grid grid = Grid();

	Snake snake = Snake();
	std::vector<sf::CircleShape> snakeBody;
	sf::CircleShape snakeHead;
	sf::Vector2f snakeHeadPosition;
	float snakeX;
	float snakeY;

	Food food = Food();
	sf::CircleShape foodDrawn;
	sf::Vector2f foodPosition;
	float foodX;
	float foodY;
	bool foodSpawn = true;
	
	bool startingMove = true;
	bool DKeyPressedOnce = false;
	bool AKeyPressedOnce = false;
	bool SKeyPressedOnce = false;
	bool WKeyPressedOnce = false;

	std::random_device rd;
	std::mt19937 gen(rd());
	int lower_bound = 0;
	int upper_bound = 800;
	std::uniform_int_distribution<int> distribution(lower_bound/50, upper_bound/50);
	int randomX;
	int randomY;
	int staticX;
	int staticY;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (const auto& cells : grid.draw()) { //this loop draw the grid onto the window
			window.draw(cells);
		}

		for (const auto& segment : snake.getBody()) { //this loop draw the snake onto the window
			window.draw(segment);
		}

		//code below implement the snake movement 
		//this code track if the key is held down
		bool DKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		bool AKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		bool SKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		bool WKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);


		//snake will go right for these two if statements
		
		 if (!snake.isHitWall() && !snake.isHitBody() && DKeyPressed && !DKeyPressedOnce && !AKeyPressedOnce) {
			snake.moveRight();

			SKeyPressedOnce = false;
			WKeyPressedOnce = false;
			startingMove = false;

			DKeyPressedOnce = true;
		}

		else if (!snake.isHitWall() && !snake.isHitBody() && DKeyPressedOnce && !SKeyPressed && !WKeyPressed)
			snake.moveRight();


		//snake will go left for these two if statements
		else if (!snake.isHitWall() && !snake.isHitBody() && AKeyPressed && !AKeyPressedOnce && !DKeyPressedOnce) {
			snake.moveLeft();

			WKeyPressedOnce = false;
			SKeyPressedOnce = false;
			startingMove = false;

			AKeyPressedOnce = true;
		}
		else if (!snake.isHitWall() && !snake.isHitBody() && AKeyPressedOnce && !SKeyPressed && !WKeyPressed)
			snake.moveLeft();



		//snake will go down for these two if statements
		else if (!snake.isHitWall() && !snake.isHitBody() && SKeyPressed && !SKeyPressedOnce && !WKeyPressedOnce) {
			snake.moveDown();

			AKeyPressedOnce = false;
			DKeyPressedOnce = false;
			startingMove = false;

			SKeyPressedOnce = true;
		}

		else if (!snake.isHitWall() && !snake.isHitBody() && SKeyPressedOnce && !DKeyPressed && !AKeyPressed)
			snake.moveDown();


		//snake will go up for these two if statements
		else if (!snake.isHitWall() && !snake.isHitBody() && WKeyPressed && !WKeyPressedOnce && !SKeyPressedOnce) {
			snake.moveUp();

			AKeyPressedOnce = false;
			DKeyPressedOnce = false;
			startingMove = false;

			WKeyPressedOnce = true;
		}
		else if (!snake.isHitWall() && !snake.isHitBody() && WKeyPressedOnce && !DKeyPressed && !AKeyPressed)
			snake.moveUp();
		 //the snake will move to the right if no key is pressed
		else if (!snake.isHitWall() && !snake.isHitBody() && startingMove) {
			 snake.moveRight();
		 }

		 if (snake.isHitWall() || snake.isHitBody()) {
			 snake.gameOver();
		 }

		//implement the snake eating the food and the food randomly appearing on another grid after being eaten
		 if (foodSpawn) {
			 randomX = distribution(gen);
			 randomY = distribution(gen);
			 staticX = randomX;
			 staticY = randomY;
			 foodSpawn = false;
		 }
		 else if (snakeX == foodX && snakeY == foodY) {
			 foodSpawn = true;
		 }

		 snakeBody = snake.getBody();
		 snakeHead = snakeBody.back();
		 snakeHeadPosition = snakeHead.getPosition();
		 snakeX = snakeHeadPosition.x;
		 snakeY = snakeHeadPosition.y;

		 foodDrawn = food.draw(staticX * 50, staticY * 50);
		 foodPosition = foodDrawn.getPosition();
		 foodX = foodPosition.x;
		 foodY = foodPosition.y;

		 if (snakeX == foodX && snakeY == foodY)
			 snake.grow();
		 
		
		 window.draw(foodDrawn);
		
		 window.display();
	}

	return 0;
}