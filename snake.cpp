#include "snake.h"


snake::snake(std::pair<int, int> head){
	this->startheadLocalization = head;
	this->initialize();
	//addElement(head.first-1, head.second);
}

void snake::print() {
	std::cout << "x= " << this->head.first << " y= " << head.second << std::endl;
}

void snake::move() {
	int x = head.first;
	int y = head.second;
	switch (dir)
	{
	case UP:
		head.second--;
		break;
	case DOWN:
		head.second++;
		break;
	case LEFT:
		head.first--;
		break;
	case RIGHT:
		head.first++;
		break;
	default:
		break;
	}
	for (int i = 0; i < body.size(); i++) {
		std::swap(x, body.at(i).first);
		std::swap(y, body.at(i).second);
	}
}

std::pair<int, int> snake::getHead() {
	return head;
}


void snake::turnLeft() {
	if (dir != RIGHT && dir != LEFT) {
		dir = LEFT;
	}
}
void snake::turnRight() {
	if (dir != RIGHT && dir != LEFT) {
		dir = RIGHT;
	}
}
void snake::turnUp() {
	if (dir != UP && dir != DOWN) {
		dir = UP;
	}
}
void snake::turnDown() {
	if (dir != UP && dir != DOWN) {
		dir = DOWN;
	}
}

void snake::setHead(int x, int y) {
	this->head.first = x;
	this ->head.second = y;
}

void snake::addElement(int x, int y) {
	std::pair<int, int> p;
	p.first = x;
	p.second = y;
	//std::swap(head.first, p.first);
	//std::swap(head.second, p.second);
	body.push_back(p);
}

void snake::initialize() {
	this->head = startheadLocalization;
	this->dir = RIGHT;
	body.clear();
}

std::pair<int, int> snake::getLastElement() {
	if (body.size() == 0) return head;
	else return body.at(body.size() - 1);
}

snake::~snake()
{
}
