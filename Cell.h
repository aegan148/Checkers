#pragma once
#include <utility>

using pos=std::pair<size_t, size_t>;

class Cell { //�������� �� ���� ������ �� �����
public:
	enum class State { Black, White, Empty }; //������������ ��������� ������
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