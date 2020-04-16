#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
#include "snake.h"
#include <Windows.h>
#include "food.h"

class gameManager
{
	std::vector<food> foods;
public:
	void move(snake *sss);
	void eating(snake *sss);
	void setFood();
	gameManager();
	~gameManager();
};

