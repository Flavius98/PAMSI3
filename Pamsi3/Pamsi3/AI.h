#pragma once
#include "Player.h"
#include <climits>
#include <ctime>
#include <algorithm>
class AI : public Player {
    int minimax(Board& b, int depth, int isMaximizing, int alpha, int beta);
    void BestMove(Board& b);

public:
    AI() = default;
    AI(char sign);

    void move(Board& b);
};