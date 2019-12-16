#include "Game.h"
#include<iostream>
#include<stdlib.h>

Game::Game() :blIsSurrounder(false), blackScore(0), writeScore(0), lastPlayer(Player::BLACK)
{
}

Game::~Game()
{
}

Game::Player Game::GetWiner()
{
	Player winner(Player::NONE);

	if (blIsSurrounder) {
		if (lastPlayer == Player::WHITE)
		{
			winner = Player::BLACK;
		}
		else if (lastPlayer == Player::BLACK)
		{
			winner = Player::WHITE;
		}
	}
	else {
		if (writeScore == 12) {
			winner = Player::WHITE;
		}
		else if (blackScore == 12) {
			winner = Player::BLACK;
		}
	}
	return std::move(winner);
}

void Game::Start()
{
	mBoard.ResetMap();

	while (GetWiner() == Player::NONE) {
		
		Board::MoveResult moveResult = Board::MoveResult::PROHIBITED;

		while (moveResult==Board::MoveResult::PROHIBITED) {
			//IO stuff
			bool direction = GetDirection();
			auto newMove = makeIO();

			moveResult = mBoard.makeMove(newMove.first, newMove.second, direction);
		}
		//pars moveResult
		if (moveResult == Board::MoveResult::SUCCESSFULL_COMBAT) {
			//update score
			UpdateScore();

		}
		//update last player
		SwitchPlayer();

	}
}

bool Game::GetDirection() const
{
	bool direction;
	switch (lastPlayer) {
	case Player::WHITE :
			direction = false;
			break;
	case Player::BLACK :
		direction = true;
		break;
	default:
		break;
	}

	return std::move(direction);
}

movePos Game::makeIO()
{
	system("cls");
	auto map = mBoard.GetMap();//print board
	mIO.drawBoard(map);
	auto newMove = mIO.GetMove();//ask for a move
	return std::move(newMove);
}

void Game::SwitchPlayer()
{
	if (lastPlayer == Player::WHITE) {
		lastPlayer = Player::BLACK;
	}
	else {
		lastPlayer = Player::WHITE;
	}
}

void Game::UpdateScore()
{
	if (lastPlayer == Player::WHITE) {
		blackScore++;
	}
	else {
		writeScore++;
	}
}
