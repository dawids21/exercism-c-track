#include "queen_attack.h"
#include "stdbool.h"
#include "stdlib.h"

static bool checkRow(position_t queen1, position_t queen2);
static bool checkColumn(position_t queen1, position_t queen2);
static bool checkDiagonal(position_t queen1, position_t queen2);

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (queen_1.column >= 8 || queen_1.row >= 8 ||
        queen_2.column >= 8 || queen_2.row >= 8 ||
        (queen_1.row == queen_2.row && queen_1.column == queen_2.column))
    {
        return INVALID_POSITION;
    }
    if (checkRow(queen_1, queen_2) || checkColumn(queen_1, queen_2) || checkDiagonal(queen_1, queen_2))
    {
        return CAN_ATTACK;
    }
    return CAN_NOT_ATTACK;
}

static bool checkRow(position_t queen1, position_t queen2)
{
    return queen1.row == queen2.row;
}

static bool checkColumn(position_t queen1, position_t queen2)
{
    return queen1.column == queen2.column;
}

static bool checkDiagonal(position_t queen1, position_t queen2)
{
    return abs(queen1.row - queen2.row) == abs(queen1.column - queen2.column);
}