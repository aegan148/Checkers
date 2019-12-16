#pragma once
#include"Cell.h"
#include <map>

using map= std::map<pos, Cell>;

class Board
{
public:
	Board();
	~Board();
	enum class MoveResult {SUCCEFULL_MOVE, SUCCESSFULL_COMBAT, PROHIBITED};
	void ResetMap();
	MoveResult makeMove(const pos& startPos, const pos& endPos, bool direction, bool forceCombat=false);
	const map& GetMap() const { return mCells; }
private:
	const size_t BoardSize;
	map mCells;
	MoveResult checkMove(const pos& startPos, const pos& endPos, bool direction);

};

