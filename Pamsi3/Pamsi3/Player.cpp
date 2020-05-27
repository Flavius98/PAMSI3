#include "Player.h"

bool Player::operator == (const Player& p)
{
	if (this->Sign == p.Sign)
		return true;

	else
		return false;
}

char Player::GetSign()
{
	return Sign;
}

std::pair<int, int> Player::inputs(int& InputX, int& InputY, int limit)
{
	std::cout << "Numer wiersza: ";
	std::cin >> InputX;

	while (std::cin.fail())
	{
		std::cout << "Blad wpisz ponownie" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cin >> InputX;
	}

	while (InputX<0 || InputX >limit)
	{
		std::cout << "Koordynacje wykraczaja poza skale, wpisz ponownie" << std::endl;
		std::cin >> InputX;
	}

	std::cout << "Numer kolumny: ";
	std::cin >> InputY;

	while (std::cin.fail())
	{
		std::cout << "Blad wpisz ponownie" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cin >> InputY;
	}

	while (InputX<0 || InputY >limit)
	{
		std::cout << "Koordynacje wykraczaja poza skale, wpisz ponownie" << std::endl;
		std::cin >> InputY;
	}
	return std::make_pair(InputX, InputY);
}


void Player::move(Board& board)
{
	int InputX; int InputY;

	std::pair<int, int> Inputs;
	std::cout << "Ruch gracza " << this->Sign << std::endl;

	do
	{
		Inputs = inputs(InputX, InputY, board.GetSize() - 1);
	} while (!board.CheckIfEmpty(Inputs.first, Inputs.second));

	board.PutOnBoard(Inputs.first, Inputs.second, Sign);
}