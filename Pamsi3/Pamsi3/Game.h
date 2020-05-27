#pragma once

#include "Player.h"
#include "AI.h"
#include "Board.h"

class Game {
	Board board;
	Player player1;
	Player player2;
	AI AIplayer;

public:
	void StartGame(int choice, bool current);

	Game(int size, int matchPoint);
};