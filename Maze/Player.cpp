#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEndterPos();
	_board = board;
}

void Player::Update(uint64 deltaTick)
{

}
