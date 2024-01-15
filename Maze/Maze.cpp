#include "pch.h"
#include <iostream>
#include "ConsoleHelper.h"
#include "board.h"

Board board;

int main()
{
	board.Init(25);

	uint64 lastTick = 0;

	while (true)
	{
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;


		board.Render();
	}
}

