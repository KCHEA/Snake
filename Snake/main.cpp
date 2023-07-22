#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Snake.h"
#include "Food.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Snake");
	window.setFramerateLimit(3);
	
	Grid grid = Grid();
	Snake snake = Snake();
	Food food = Food();

	sf::CircleShape foodDrawn;
	sf::Vector2f foodPosition;
	
	
	bool DKeyPressedOnce = false;
	bool AKeyPressedOnce = false;
	bool SKeyPressedOnce = false;
	bool WKeyPressedOnce = false;

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
		

		//draw the food first
		foodDrawn = food.draw();
		foodPosition = foodDrawn.getPosition();

		window.draw(foodDrawn);

		//snake will go right for these two if statements
		if (!snake.isHitWall() && DKeyPressed && !DKeyPressedOnce && !AKeyPressedOnce) {
			snake.moveRight();

			SKeyPressedOnce = false;
			WKeyPressedOnce = false;

			DKeyPressedOnce = true;
		}

		else if (!snake.isHitWall() && DKeyPressedOnce && !SKeyPressed && !WKeyPressed)
			snake.moveRight();


		//snake will go left for these two if statements
		else if (!snake.isHitWall() && AKeyPressed && !AKeyPressedOnce && !DKeyPressedOnce) {
			snake.moveLeft();

			WKeyPressedOnce = false;
			SKeyPressedOnce = false;
			
			AKeyPressedOnce = true;
		}
		else if (!snake.isHitWall() && AKeyPressedOnce && !SKeyPressed && !WKeyPressed) 
			snake.moveLeft();
		


		//snake will go down for these two if statements
		else if (!snake.isHitWall() && SKeyPressed && !SKeyPressedOnce && !WKeyPressedOnce) {
			snake.moveDown();

			AKeyPressedOnce = false;
			DKeyPressedOnce = false;

			SKeyPressedOnce = true;
		}

		else if (!snake.isHitWall() && SKeyPressedOnce && !DKeyPressed && !AKeyPressed)
			snake.moveDown();


		//snake will go up for these two if statements
		else if (!snake.isHitWall() && WKeyPressed && !WKeyPressedOnce && !SKeyPressedOnce) {
			snake.moveUp();

			AKeyPressedOnce = false;
			DKeyPressedOnce = false;

			WKeyPressedOnce = true;
		}
		else if (!snake.isHitWall() && WKeyPressedOnce && !DKeyPressed && !AKeyPressed)
			snake.moveUp();
		
		
		

		
		
		//implement the snake eating the apple

		
		
		window.display();
	}

	return 0;
}