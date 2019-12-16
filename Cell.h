#pragma once
#include <utility>

using pos=std::pair<size_t, size_t>;

class Cell { //отвечает за одну клетку на доске
public:
	enum class State { Black, White, Empty }; //перечесление возможных клеток
	Cell(State state);
	~Cell();
	State GetState() const { return mState; };
	void setStete(State state) { this->mState = state; }

	//const pos& getPosition() const { return mPosition; }
	//void setPosition(const pos& posit) { this->mPosition = posit; }

private:
	State mState;
	//pos mPosition;
};