#include "Game.h"

Game::Game(int size, int matchPoint) : board(size, matchPoint), player1('X'), player2('O'), AIplayer('O') {}

void Game::StartGame(int choice, bool current)
{
	bool EndGame = true;

	while (EndGame)
	{
		std::cout << "TIC TAC TOE!!!!" << std::endl;
		board.PrintBoard();

		if (current == true)
			player1.move(board);

		else
		{
			if (choice == 1)
				AIplayer.move(board);
			else
				player2.move(board);
		}

		system("CLS");

		if (board.CheckWinnerUltimate() == 1)
		{
			std::cout << "Player X won" << std::endl;
			board.PrintBoard();
			EndGame = false;
		}

		else if (board.CheckWinnerUltimate() == -1)
		{
			std::cout << "Player O won" << std::endl;
			board.PrintBoard();
			EndGame = false;
		}

		else if (board.CheckFull() && board.CheckWinnerUltimate() != -1 && board.CheckWinnerUltimate() != 1) 
		{
			std::cout << "TIE" << std::endl;
			board.PrintBoard();
			EndGame = false;
		}

		if (current == true)
			current = false;

		else
			current = true;
	}
}