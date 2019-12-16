#include "IO.h"
#include<iostream>


movePos IO::GetMove()
{
	movePos position;
	size_t p1,p2;

	std::cin >> p1;
	std::cin >> p2;

	position.first.first = p1 / 10;
	position.first.second = p1 - 10* position.first.first;

	position.second.first = p2 / 10;
	position.second.second = p2 - 10 * position.second.first;

	return std::move(position);
}

std::string IO::CastState(Cell::State state)
{
	std::string result("");
	switch (state)
	{
	case Cell::State::Black:
		result = "B";
		break;
	case Cell::State::White:
		result = "W";
		break;
	default:
		result = " ";
		break;
	}
	return std::move(result);
}

void IO::drawBoard(const map& board)
{
	// parsing map
	size_t BoardSize = sqrt(board.size());
	for (size_t i = 0; i < BoardSize; i++) {
		std::cout << "|" ;
		for (size_t j = 0; j < BoardSize; j++) {
			std::cout << CastState(board.at(pos(i, j)).GetState());
			std::cout << "|" ;
		}
		std::cout << std::endl;
	}
}

