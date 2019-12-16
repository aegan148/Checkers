#include "Board.h"

Board::Board() : BoardSize(8)
{
}

Board::~Board()
{
}

void Board::ResetMap()
{
	
	for (size_t i = 0; i < BoardSize; i++) {
		for (size_t j = 0; j < BoardSize; j++) {
			Cell::State state(Cell::State::Empty);
			if (i == 0 && j % 2 != 0) {
				state = Cell::State::Black;
			}
			else if (i == 1 && j % 2 == 0) {
				state = Cell::State::Black;
			}
			else if (i == 2 && j % 2 != 0) {
				state = Cell::State::Black;
			}
			//////////////////////////////////////////////////////////////
			else if (i == 5 && j % 2 == 0) {
				state = Cell::State::White;
			}
			else if (i == 6 && j % 2 != 0) {
				state = Cell::State::White;
			}
			else if (i == 7 && j % 2 == 0) {
				state = Cell::State::White;
			}
			
			pos Position = pos(i, j);
			Cell  cells = Cell(state);
			mCells.insert({ std::move(Position), std::move(cells) });
		}
	}
}

Board::MoveResult Board::makeMove(const pos& startPos, const pos& endPos, bool direction, bool forceCombat)
{
	auto moveResult = checkMove(startPos, endPos, direction); 
	
	switch (moveResult) {
	case Board::MoveResult::SUCCEFULL_MOVE:
		mCells.at(endPos).setStete(mCells.at(startPos).GetState());
		mCells.at(startPos).setStete(Cell::State::Empty);
		break;

	case Board::MoveResult::SUCCESSFULL_COMBAT :
		mCells.at(endPos).setStete(mCells.at(startPos).GetState());
		mCells.at(startPos).setStete(Cell::State::Empty);
		mCells.at(pos((startPos.first + endPos.first) / 2, (startPos.second + endPos.second) / 2)).setStete(Cell::State::Empty);
		break;
	}
	
	return MoveResult();
}

Board::MoveResult Board::checkMove(const pos& startPos, const pos& endPos, bool direction)
{
	Board::MoveResult result = Board::MoveResult::PROHIBITED;
	const int dY = endPos.first- startPos.first;
	const int dX = endPos.second - startPos.second;
	bool is_Combat = false;

	if (endPos.first >= 0 && endPos.first < BoardSize && endPos.second >= 0 && endPos.second < BoardSize) {
		auto targetCellState = mCells.at(endPos).GetState();
		
		if (targetCellState == Cell::State::Empty) {

			if (abs(dX) == 2 && abs(dY) == 2) {
				pos victimPos((startPos.first + endPos.first) / 2, (startPos.second + endPos.second) / 2);
				auto victimCellState = mCells.at(victimPos).GetState();
				auto startCellState = mCells.at(startPos).GetState();

				result = targetCellState != victimCellState && startCellState != victimCellState ? Board::MoveResult::SUCCESSFULL_COMBAT : result;
			}
			else if ((abs(dX) == 1 && dY == 1 && direction) || (abs(dX) == 1 && dY == -1 && !direction)) {
				result = Board::MoveResult::SUCCEFULL_MOVE;
			}
		}
	}
	return result;
}
