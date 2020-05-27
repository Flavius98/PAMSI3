#include "AI.h"

AI::AI(char sign) : Player(sign) {}

void AI::move(Board& b)
{
    BestMove(b);
}


void AI::BestMove(Board& b) {
    int bestScore = INT_MIN;

    std::pair<int, int> move = std::make_pair(-1, -1);

    for (int i = 0; i < b.GetSize(); i++) 
        for (int j = 0; j < b.GetSize(); j++) 
            if (b.CheckIfEmpty(i, j))                      
            {
                b.PutOnBoard(i, j, GetSign());
                int score = minimax(b, 0, false, INT_MIN, INT_MAX);
                b.PutOnBoard(i, j, ' ');

                if (score > bestScore) 
                {
                    bestScore = score;
                    move = std::make_pair(i, j);
                }
            }
    b.PutOnBoard(move.first, move.second, GetSign());
}


int AI::minimax(Board& b, int depth, int isMaximizing, int alpha, int beta)
{
    int result = b.CheckWinnerUltimate();

    if (result == 1)
        return -10 + depth;

    else if (result == -1)
        return 10 - depth;

    else if (b.CheckFull() || depth == 5)
        return 0;

    if (isMaximizing) 
    {
        int best = INT_MIN;

        for (int i = 0; i < b.GetSize(); i++) 
            for (int j = 0; j < b.GetSize(); j++) 
                if (b.CheckIfEmpty(i, j)) 
                {
                    b.PutOnBoard(i, j, GetSign());
                    best = std::max(minimax(b, depth + 1, false, alpha, beta), best);
                    b.PutOnBoard(i, j, ' ');
                    alpha = std::max(best, alpha);

                    if (alpha >= beta)
                        break;
                }
        return best;
    }

    else 
    {
        int best = INT_MAX;

        for (int i = 0; i < b.GetSize(); i++) 
            for (int j = 0; j < b.GetSize(); j++) 
                if (b.CheckIfEmpty(i, j)) 
                {
                    b.PutOnBoard(i, j, 'X');
                    best = std::min(minimax(b, depth + 1, true, alpha, beta), best);
                    b.PutOnBoard(i, j, ' ');

                    beta = std::min(beta, beta);
                    if (alpha >= beta) 
                        break;
                }
        return best;
    }
}