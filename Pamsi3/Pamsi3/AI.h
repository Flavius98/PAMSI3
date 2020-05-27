#pragma once

#include <climits>
#include <ctime>
#include <algorithm>

#include "Player.h"

class AI : public Player {
    int minimax(Board& b, int depth, int isMaximizing, int alpha, int beta);
    void BestMove(Board& b);

public:
    void move(Board& b);
    
    AI() = default;
    AI(char sign);
};