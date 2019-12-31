#include "IO.h"
#include<iostream>
#include<algorithm>


void IO::printScore(size_t whiteScore, size_t BlackSkore)
{
	std::cout << " White player score: " << whiteScore << std::endl;
	std::cout << " Black player score: " << BlackSkore << std::endl<< std::endl;
}

movePos IO::GetMove(std::string player)
{
	movePos position;
	size_t p1,p2;
	std::string line1, line2;

	std::cout <<std::endl<< player << " moving\n"<<std::endl<<"Enter the coordinates like that: 21(from y=2,x=1), 32(to y=3x=2) or 'ff' to leave game\n";

	std::cin >> line1;
	std::cin >> line2;
	bool isLine1Number=true, isLine2Number=true;

	std::for_each(line1.cbegin(), line1.cend(), [&](char c) {if (!isdigit(c)) { isLine1Number = false; }; });
	std::for_each(line2.cbegin(), line2.cend(), [&](char c) {if (!isdigit(c)) { isLine2Number = false; }; });

	if (!isLine1Number || !isLine2Number) {
		if (line1 == "ff") {
			// 0000 move is surender
			position.first.first = 0;
			position.first.second = 0;
			position.second.first = 0;
			position.second.second = 0;
		}
		else {
			// is bad user's input
			position.first.first = 1;
			position.first.second = 1;
			position.second.first = 1;
			position.second.second = 1;
		}
	}
	else {
		p1 = (size_t)std::stoi(line1);
		p2 = (size_t)std::stoi(line2);

		position.first.first = p1 / 10;
		position.first.second = p1 - 10 * position.first.first;

		position.second.first = p2 / 10;
		position.second.second = p2 - 10 * position.second.first;
	}

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

void IO::endGame(std::string player)
{
	std::cout << std::endl<< "Game over!" << std::endl<< player << " wins!"<< std::endl;
}

