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
	static movePos GetMove();
	static void drawBoard(const map& board);
	static std::string CastState(Cell::State state);
private:
	
};

