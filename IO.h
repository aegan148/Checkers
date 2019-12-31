#pragma once
#include<utility>
#include <map>
#include <string>
#include"Cell.h"


class Cell;
using pos=std::pair<size_t, size_t>;
using movePos=std::pair<pos, pos>;
using map= std::map<pos, Cell>;

class IO
{
public:
	IO() {};
	~IO() {};
	void printScore(size_t whiteScore, size_t BlackSkore);
	movePos GetMove(std::string player);
	void drawBoard(const map& board);
	void endGame(std::string player);
	std::string CastState(Cell::State state);
private:
	
};

