#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>

#include "TicTacToeField.h"

using namespace std;


TicTacToeField::TicTacToeField(){

    //field.push_back({ 0, 0, 0 });
    //field.push_back({ 0, 0, 0 });
    //field.push_back({ 0, 0, 0 });

    for (int j = 0; j <= rowZahl; ++j) {
        v1.push_back(0);
    }

    for (int i = 0; i <=colZahl ; ++i) {
        field.push_back(v1);
    }
}

TicTacToeField::TicTacToeField(vector<vector<int>> &field) {

    this->field = field;

    //ich bin der Constructor, dem die Variable field uebergeben wird
}

int TicTacToeField::calculateWinner() {

    for (int i = 0; i <= 2; i++) {

        if (field.at(i).at(0) != 0 &&
            field.at(i).at(0) == field.at(i).at(1) &&
            field.at(i).at(0) == field.at(i).at(2))
        {
            return field.at(i).at(0);
        }

        else if (field.at(0).at(i) != 0 &&
            field.at(0).at(i) == field.at(1).at(i) &&
            field.at(0).at(i) == field.at(2).at(i))
        {
            return field.at(0).at(i);
        }
    }

    if (field.at(0).at(0) != 0 &&
        field.at(0).at(0) == field.at(1).at(1) &&
        field.at(0).at(0) == field.at(2).at(2))
    {
        return field.at(0).at(0);
    }

    if (field.at(0).at(2) != 0 &&
        field.at(0).at(2) == field.at(1).at(1) &&
        field.at(0).at(2) == field.at(2).at(0))
    {
        return field.at(0).at(2);
    }

    return 0;
}

string TicTacToeField::getFielStr() {

    stringstream result;

    for (const auto& row : field) {

        result << " | ";

        for (const auto& item : row) {

            result << item << " | ";

        }
        result << endl;
    }

    return result.str();
}

