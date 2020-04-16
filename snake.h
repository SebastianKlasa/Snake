#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "element.h"

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class snake : public element 
{
	Direction dir;
	std::pair<int, int> head;
	std::pair<int, int> startheadLocalization;
	friend class gameManager;
public:
	std::vector<std::pair<int, int>> body;
	snake(std::pair<int, int> head);
	void print();
	void move();
	void turnLeft();
	void turnRight();
	void turnUp();
	void turnDown();
	void setHead(int x, int y);
	void addElement(int x, int y);
	std::pair<int, int> getHead();
	std::pair<int, int> getLastElement();
	void initialize();
	~snake();
};

