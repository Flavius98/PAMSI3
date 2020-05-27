#pragma once

#include "Board.h"

class Player{
	char Sign;

public:
	char GetSign();
	std::pair<int, int> inputs(int& InputX, int& InputY, int limit);
	virtual void move(Board& board);

	bool operator==(const Player& p);

	Player() = default;
	Player(char sign) :Sign(sign) {};
	~Player() {};
};