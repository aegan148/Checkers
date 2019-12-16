#pragma once
#include "Board.h"
#include "IO.h"
#include "Cell.h"

class Game
{
public:
	enum class Player { NONE, BLACK, WHITE };
	Game();
	~Game();
	Player GetWiner();
	void Start();
private:
	bool GetDirection()const;
	movePos makeIO();
	size_t writeScore;
	size_t blackScore;
	void SwitchPlayer();
	void UpdateScore();
	Player lastPlayer;
	bool blIsSurrounder;
	Board mBoard;
	IO mIO;
};

