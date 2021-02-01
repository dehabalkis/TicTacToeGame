#pragma once


#include <vector>
#include <string>
#include <sstream>

class TicTacToeField
{

//private:


protected:

	std::vector <std::vector<int>> field;

	std::vector<int> v1;

	int rowZahl = 2, colZahl = 2;

public:


	TicTacToeField();

	TicTacToeField(std::vector<std::vector<int>> &field);

	int calculateWinner();

	std::string getFielStr();

};