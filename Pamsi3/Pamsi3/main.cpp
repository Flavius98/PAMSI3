#include <stdlib.h>
#include <chrono>
#include <thread>

#include "Board.h"
#include "Player.h"
#include "AI.h"
#include "Game.h"

int main()
{
	int matchPoint = 0;
	int size = 0;
	int choice;

	bool choice2 = 1;
	bool playing = true;


	while (playing)
	{
		std::cout << "Wybierz tryb gry: " << std::endl;
		std::cout << "1. Tryb jednoosobowy" << std::endl;
		std::cout << "2. Tryb dla dwoch graczy" << std::endl;
		std::cin >> choice;

		while (std::cin.fail())
		{
			std::cout << "Blad wpisz ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			std::cin >> choice;
		}

		std::cout << "Podaj wymiar tablicy: ";
		std::cin >> size;

		while (std::cin.fail())
		{
			std::cout << "Blad wpisz ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			std::cin >> size;
		}

		std::cout << "Liczba potrzebnych znakow w rzedzie do wygranej: ";
		std::cin >> matchPoint;

		while (std::cin.fail())
		{
			std::cout << "Blad wpisz ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			std::cin >> matchPoint;
		}

		if (choice == 1)
		{
			std::cout << "0. Zaczyna AI" << std::endl << "1. Zaczyna gracz " << std::endl;
			std::cin >> choice2;

			while (std::cin.fail())
			{
				std::cout << "Blad wpisz ponownie" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000000, '\n');
				std::cin >> matchPoint;
			}
		}

		system("CLS");
		Game g(size, matchPoint);
		g.StartGame(choice, choice2);

		std::cout << "Chcesz zagrac jeszcze raz? 0 - nie ;;; 1 - tak ";
		std::cin >> playing;
	}
	return 0;
}