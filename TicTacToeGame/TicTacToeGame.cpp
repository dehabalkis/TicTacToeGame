#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "TicTacToeGame.h"

using namespace std;

TicTacToeGame::TicTacToeGame(string player1,string player2) {

	this->player1 = player1;
	this->player2 = player2;

	currentPlayer = 1;

}

void TicTacToeGame::play(int row, int col) {

    if (row < 0 || row >= this->field.size()) {

        return;

    }

    if (col < 0 || col >= this->field.size()) {

        return;

    }

    if (this->field[row][col] != 0) {

        return;

    }

    this->field[row][col] = currentPlayer;

    if (currentPlayer == 1) {

        currentPlayer = 2;
    }
    else {

        currentPlayer = 1;
    }
}

bool TicTacToeGame::isFinisched() {

    int winner = TicTacToeField::calculateWinner();

    if (winner != 0) {

        return true;
    }

    for (const auto& row : field) {

        for (const int& value : row) {

            if (value == 0) {

                return false;

            }
        }
    }

    return true;
}

string TicTacToeGame::getCurrentPlayer() {

	if (currentPlayer != 1) {

		return player2;
	}
	else {

		return player1;
	}
}

std::string TicTacToeGame::getWinner(){

    if (!isFinisched()) {

        return "";

    }
    else {

        int winner = TicTacToeField::calculateWinner();

        if (winner == 0) {

            return "Unentschied";

        }
        else if (winner == 1) {

            return player1;

        }
        else {

            return player2;

        }
    }

}

std::string TicTacToeGame::getFieldStr(){

    stringstream result;

    result << endl;
    result << "Player 1 : " << player1 << endl;
    result << "Player 2 : " << player2 << endl;
    result << endl;

    result << TicTacToeField::getFielStr();

	return result.str();
}

