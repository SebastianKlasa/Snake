#pragma once
#include <vector>

class food
{
	int points;
public:
	std::pair<int, int> pos;
	food(int points, std::pair<int, int> pos);
	~food();
};

