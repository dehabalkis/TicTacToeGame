#pragma once


#include <vector>
#include <string>
#include <sstream>

#include "TicTacToeField.h"

class TicTacToeGame : public TicTacToeField
{

//private:


protected:

	std::string player1;
	std::string player2;
	int currentPlayer;

public:

	TicTacToeGame(std::string player1, std::string player2);
	void play(int row, int col);
	bool isFinisched();

	std::string getCurrentPlayer();
	std::string getWinner();
	std::string getFieldStr();

};