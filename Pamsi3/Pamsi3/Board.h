#pragma once

#include <iostream>
#include <vector>

class Board {
    int BoardSize;
    int MatchPoints;

    std::vector<std::vector<char>> Squares;
    
public:
    Board() = default;
    Board(int size, int matchpoint);

    void PrintBoard();
    int GetSize();
    int GetMatchPoint();
    bool CheckIfEmpty(int inputx, int inputy);
    void PutOnBoard(int inputx, int inputy, char sign);
   
    void printLines(int columns);
    void printNumbers(int columns);

    int CheckWinnerHorizontally();
    int CheckWinnerPerpendicularly();
    int CheckWinnerDiagonally();
    int CheckWinnerDiagonallyInverse();

    bool CheckIfEmptyBoard();
    bool CheckFull();
    int CheckWinnerUltimate();
    std::vector<std::vector<char>> GetSquare();

    ~Board() {};
};