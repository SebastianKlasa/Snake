#include "gameManager.h"
#include <thread>
#include <iostream>

#define PIX 10
#define H 60
#define W 60

void controllerManager(sf::Event event, sf::RenderWindow *window, snake *sss) {
	while ((*window).isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			sss->turnLeft();
			std::cout << "lewo" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			sss->turnRight();
			std::cout << "prawo" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sss->turnUp();
			std::cout << "góra" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			sss->turnDown();
			std::cout << "dol" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			(*window).close();
		}
		Sleep(100);
		while ((*window).pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				(*window).close();
		}
	}
}

gameManager::gameManager(){
	sf::RenderWindow window(sf::VideoMode(W*PIX+200, H*PIX), "snake");
		
	int x1 = 0, x2 = PIX;
	int y1 = 0, y2 = PIX;

	sf::ConvexShape s(4);

	snake sss(std::pair<int, int>(8, 8));
	sss.addElement(7, 8);

	sss.print();

	sf::Event event;
	std::thread control(controllerManager, event, &window, &sss);

	srand(time(NULL));

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(0, 0, 0));
		s.setFillColor(sf::Color(0, 255, 0));
		s.setPoint(0, sf::Vector2f(0, 0));
		s.setPoint(1, sf::Vector2f(W*PIX, 0));
		s.setPoint(2, sf::Vector2f(W*PIX, PIX));
		s.setPoint(3, sf::Vector2f(0, PIX));
		window.draw(s);

		s.setPoint(0, sf::Vector2f(0, 0));
		s.setPoint(1, sf::Vector2f(PIX, 0));
		s.setPoint(2, sf::Vector2f(PIX, H*PIX));
		s.setPoint(3, sf::Vector2f(0, H*PIX));
		window.draw(s);

		s.setPoint(0, sf::Vector2f((W)*PIX, 0));
		s.setPoint(1, sf::Vector2f((W + 1)*PIX, 0));
		s.setPoint(2, sf::Vector2f((W + 1)*PIX, H*PIX));
		s.setPoint(3, sf::Vector2f((W)*PIX, H*PIX));
		window.draw(s);

		s.setPoint(0, sf::Vector2f(0, (H - 1)*PIX));
		s.setPoint(1, sf::Vector2f(W*PIX, (H - 1)*PIX));
		s.setPoint(2, sf::Vector2f(W*PIX, H*PIX));
		s.setPoint(3, sf::Vector2f(0, H*PIX));
		window.draw(s);

		s.setFillColor(sf::Color(255, 0, 0));
		s.setPoint(0, sf::Vector2f(sss.getHead().first*PIX, sss.getHead().second*PIX));
		s.setPoint(1, sf::Vector2f(sss.getHead().first*PIX + PIX, sss.getHead().second*PIX));
		s.setPoint(2, sf::Vector2f(sss.getHead().first*PIX + PIX, sss.getHead().second*PIX + PIX));
		s.setPoint(3, sf::Vector2f(sss.getHead().first*PIX, sss.getHead().second*PIX + PIX));
		window.draw(s);
		for (int i = 0; i < sss.body.size(); i++) {
			s.setFillColor(sf::Color(255, 0, 0));
			s.setPoint(0, sf::Vector2f(sss.body.at(i).first*PIX, sss.body.at(i).second*PIX));
			s.setPoint(1, sf::Vector2f(sss.body.at(i).first*PIX + PIX, sss.body.at(i).second*PIX));
			s.setPoint(2, sf::Vector2f(sss.body.at(i).first*PIX + PIX, sss.body.at(i).second*PIX + PIX));
			s.setPoint(3, sf::Vector2f(sss.body.at(i).first*PIX, sss.body.at(i).second*PIX + PIX));
			window.draw(s);
		}
		for (int i = 0; i < foods.size(); i++) {
			s.setFillColor(sf::Color(0, 255, 0));
			s.setPoint(0, sf::Vector2f(foods.at(i).pos.first*PIX, foods.at(i).pos.second*PIX));
			s.setPoint(1, sf::Vector2f(foods.at(i).pos.first*PIX + PIX, foods.at(i).pos.second*PIX));
			s.setPoint(2, sf::Vector2f(foods.at(i).pos.first*PIX + PIX, foods.at(i).pos.second*PIX + PIX));
			s.setPoint(3, sf::Vector2f(foods.at(i).pos.first*PIX, foods.at(i).pos.second*PIX + PIX));
			window.draw(s);
		}
			eating(&sss);
			if (rand() % 10 == 0) {
				setFood();
			}

			window.display();
			Sleep(100);
			move(&sss);
		}
		control.join();
}

void gameManager::setFood() {
	int x = rand() % W;
	int y = rand() % H;

	food f1(10, std::pair<int, int>(x, y));
	foods.push_back(f1);

}

void gameManager::eating(snake *sss) {
	for (int i = 0; i < foods.size(); i++) {
		if (sss->head == foods.at(i).pos) {
			foods.erase(foods.begin() + i);
			sss->addElement(sss->getLastElement().first, sss->getLastElement().second);
		}
	}
}

void gameManager::move(snake *sss) {
	int x = sss->getHead().first;
	int y = sss->getHead().second;
	if (x > 0 && x < W && y>0 && y < H) {
		sss->move();
	}
	else {
		sss->initialize();
	}
}

gameManager::~gameManager(){
}
